#include <stdio.h>
#include <stdlib.h>

int main () {
	int n;
	
	printf ("Enter the number of items in the array:\n");
	scanf ("%i", &n);
	
	int *array;
	array = (int*)calloc (n, sizeof(int));
	
	for (int i = 0; i < n; i++)
		array[i] = i+1;
	
	printf ("The elements of array are:\n");
	
	for (int i = 0; i < n; i++) {
		printf ("%i ", array[i]);
	}
	
	free (array);
	
	return 0;		
}
