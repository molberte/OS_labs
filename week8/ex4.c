#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int n = 10;
    int size = 10 * 1024 * 1024;
    for (int i = 0; i < n; i++) {
        int *ptr = malloc(size);
        memset(ptr, 0, size);
        struct rusage usage;
        printf("Memory usage = %ld\n", usage.ru_maxrss);

        sleep(1);   
    }
    return 0;
}
