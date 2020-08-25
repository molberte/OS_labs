#include <stdio.h>


void triangle (int n) {
	char array [2*n-1];
	for (int i = 0; i < 2*n-1; i++) {
		array[i] = ' ';
	}
	
	for (int i = 0; i < n; i++) {
		array[n+i] = '*';
		array[n-i] = '*';
		
		puts (array);
		printf ("\n");
	}
}


int main () {
	int n;
	printf ("Enter the number n:");
	scanf ("%d", &n);
	triangle (n);
return 0;
}
