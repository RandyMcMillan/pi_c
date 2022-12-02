#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned long chunk;
	unsigned long index;
} chunk_index;


void populate_chunk_index(unsigned long arr[], chunk_index ci[], int size)
{
	int i;
	//printf("populate_chunk_index\n");
	ci[0].chunk = arr[0];
	ci[0].index = 0;
	ci[1].chunk = arr[1];
	ci[1].index = 1;
	printf("%lu", ci[0].chunk);
	printf("%lu.\n", ci[1].chunk);
	for (i = 2; i < size-1; i++){
		ci[i].chunk = arr[i];
		ci[i].index = i;
		//printf("i=%04lu\n",i);
		//printf("arr[i]=%04lu\n", arr[i]);
		//printf("%04lu:%04lu:%04lu\n", ci[i].chunk, ci[i].index, size);
		printf("%04lu:%04lu\n", ci[i].chunk, ci[i].index);
	};

}