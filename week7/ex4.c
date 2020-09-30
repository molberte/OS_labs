#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void * new_realloc(void *ptr, int size) {
	
	if (size == 0){
		free(ptr);
		return NULL;
	}
	
	if (ptr == NULL)
		return malloc(size);

	void* temp = ptr;
	ptr = malloc(size * sizeof(void*));
	memcpy(ptr, temp, size);

	return ptr;
}

int main(){
	int n;
	printf ("Enter the number of items in the array:\n");
	scanf ("%i", &n);
	int* ptr = calloc(n, sizeof(int));

	printf("The elements of the array are:\n ");
	for (int i = 0; i < n; i++) {
		ptr[i] = i;
		printf("%d ", ptr[i]);
	}
	
	printf ("\nEnter a new number of items in the array:\n");
	scanf ("%i", &n);
	
	new_realloc(ptr, n);
	printf("The elements of the array are:\n ");
	for (int i = 0; i < n; i++)
		printf("%d ", ptr[i]);
		
	printf("\n");	

	return 0;
}
