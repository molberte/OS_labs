#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
	int hit = 0;
	int miss = 0;
	int size = atoi(argv[1]);
	printf("size: %d\n", size);

	FILE *fp;
	fp = fopen("input.txt", "r"); 
	char buff[BUFFER_SIZE]; 
	int *page_frames = calloc(size, sizeof(int));
    int *counts = calloc(size, sizeof(int));
    memset(page_frames, 0, size);
    memset(counts, 0, size); 

	int current; 
	while (fscanf(fp, "%d", &current) != EOF){

		int index = -1;
		for (int i = 0; i < size; i++) {
	        if (current == page_frames[i]) {
	        	index = i;
	        	break;
	        }
	    }
	    if (index != -1) {
            counts[index] >>= 1;
            counts[index] |= 1<<7;
            hit++;
        } 
		else {
            int index_min = 0;
		    for (int i = 0; i < size; i++)
		        if (counts[i] < counts[index_min])
		            index_min = i;

            page_frames[index_min] = current;
            counts[index_min] = 0;
            counts[index_min] |= 1<<7;
            miss++;
        }
    }
    printf("Hit/Miss ratio: %lf\n", (double)hit/(double)miss);
	fclose(fp);
	return 0;
}
