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