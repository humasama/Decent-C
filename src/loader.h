#include <stdbool.h>

#ifdef WEAK_LOAD
#pragma weak load
#endif

bool load(char *path, char *argv[]);
