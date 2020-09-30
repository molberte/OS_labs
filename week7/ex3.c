#include <stdlib.h>
#include <stdio.h>

int main(){
	//Allows you to generate random number
	//we don't need random number here, so  just comment this line
	//srand(time(NULL));

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size:");
	int n1=0;
	scanf("%i", &n1);

	//Create a new array of n1 ints
	int *array; //it's a bad move to name anything like a1 a2 b1, so I changed the template
	array = (int*)calloc (n1, sizeof(int));
	
	for(int i = 0; i < n1; i++){
		//Set each value in a1 to 100
		array[i] = 100;
		//Print each element out (to make sure things look right)
		printf("%d ", array[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d", &n2);

	//Dynamically change the array to size n2
	array = realloc (array, sizeof(int));

	//If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

	if (n2 > n1) {
		for (int i = n1; i < n2; i++) 
			array [i] = 0;
	}
	

	for(int i=0; i<n2;i++){
		//Print each element out (to make sure things look right)
		printf("%d ", array[i]);
	}
	printf("\n");
	
	//Done with array now, done with program :D
	
	return 0;
}
