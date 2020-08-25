#include <stdio.h>

void swapping (int * var1, int * var2) {
	int temp = * var1;
	*var1 = *var2;
	*var2 = temp;
}

int main () {
	int a, b;
	printf ("Enter two integers:");
	scanf ("%d %d", &a, &b);
	swapping (&a, &b);
	printf ("The modified values are: %d and %d", a, b); 

return 0;
}
