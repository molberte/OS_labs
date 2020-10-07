#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	int n = 10;
	int mult = 10 * 1024 * 1024;
    for (int i = 0; i < n; i++) {
        int * ptr = (int*)malloc(mult);
        memset(ptr, 0, mult);
        sleep(1);
    }

    return 0;
}
