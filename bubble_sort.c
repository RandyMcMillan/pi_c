#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(unsigned long* xp, unsigned long* yp)
{
	unsigned long temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubble_sort(unsigned long arr[], unsigned long arr2[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j],  &arr[j + 1]);
				swap(&arr2[j], &arr2[j + 1]);
}
