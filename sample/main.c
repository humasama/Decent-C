#include <stdio.h>
#include <loader.h>

int main(int argc, char *argv[]) {
    if (argc > 1) {
        printf("We will start program %s by loader...", argv[1]);
    }

    load(argv[1], &argv[2]);

    return 0;
}
