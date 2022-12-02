#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to print an array */
void print_array(unsigned long arr[], int size)
{
	int i;
	printf("print_array:\n");
	printf("%lu", arr[0]);
	printf("%lu.\n", arr[1]);
	for (i = 2; i < size-1; i++)
		//printf("%04lu:     ", arr[i]);
		if (arr[i] <= 2048){
			printf("%04lu:%04d\n", arr[i], i);
		}
	//printf("\n");
}
void print_array2(unsigned long arr1[], unsigned long arr2[], int size)
{
	int i;
	printf("print_array2:\n");
	printf("%lu", arr1[0]);
	printf("%lu.\n", arr1[1]);
	for (i = 2; i < size-1; i++)
		//printf("%04lu:     ", arr1[i]);
		if (arr1[i] <= 2048){
			printf("%04lu:%04lu:%04d\n", arr1[i], arr2[i], i);
		}
	//printf("\n");
}