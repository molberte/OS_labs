#include <stdio.h> 

  
void swapping (int * var1, int * var2) {
	int temp = * var1;
	*var1 = *var2;
	*var2 = temp;
} 
   
void bubbleSort(int array[], int n)  {  
    for (int i = 0; i < n; i++)      
      	for (int j = 0; j < n-i; j++)  
    	    if (array[j] > array[j+1])  
    	        swapping(&array[j], &array[j+1]);  

}  
 
int main()  {  
	int n;
    printf ("Enter the number of elements in the array:");
    scanf ("%d", &n);
    
    
    int array[n];
    printf ("Enter the array:");
    for (int i = 0; i < n; i++)
    	scanf ("%d", &array[i]);
     
    bubbleSort(array, n);  
    printf ("Sorted array is: \n");
  	
  	 for (int i = 0; i < n; i++)
    	printf ("%d ", array[i]);
  	  
    return 0;  
} 

