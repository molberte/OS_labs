#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main () {
	char* word = (char*) malloc (sizeof(char)* BUFFER_SIZE);
	printf ("Enter your command:");
	scanf ("%s", word);
	system (word);
	
	
return 0;	
}
