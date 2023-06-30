#ifdef WEAK_LOAD
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <dlfcn.h>

#pragma weak load
extern bool load(char *path, char *argv[]);

int main(int argc, char *argv[]) {
    assert(load == NULL);
    printf("Weak symbols must be explicitly resolved by dlopen\n");

    if (argc > 1) {
        printf("We will start program %s by loader...\n", argv[1]);
    }

    void *handle;
    bool (*func)(char *, char **);
    char *error;

    handle = dlopen("../src/libload.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    dlerror();

    *(void **) (&func) = dlsym(handle, "load");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    (*func)(argv[1], &argv[2]);

    dlclose(handle);
    return 0;
}
#else
#include <stdio.h>
#include <loader.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("We will start program %s by loader...", argv[1]);
    }

    load(argv[1], &argv[2]);

    return 0;
}
#endif
