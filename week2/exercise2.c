#include <stdio.h>
#include <string.h>

int main () {
	char str [1000];
	printf ("Enter a string:");
	fgets (str, sizeof(str), stdin); 

	int length = strlen (str);

	for (int it = length-1; it >= 0; it--) {
		printf ("%c", str[it] );
	}

return 0;
}
