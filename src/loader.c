#include <stdio.h>
#include <unistd.h>

#include "loader.h"

bool load(char *path, char *argv[]) {
    if (!path) {
        printf("program path is null\n");
        return false;
    }

    execve(path, argv, NULL);

    return true;
}
