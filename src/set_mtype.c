#include <malloc.h>

void __attribute__((constructor)) set_heap_memory() {
    mallopt(M_MMAP_THRESHOLD, 0);
}
