#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print pi as an array of n digits in base BASE */
void print(unsigned long *pi, unsigned long *list, unsigned long *gt_list, int n) {
	
	int i;
	//printf("print\n");
	printf("\n");
	printf("%lu", pi[0]);
	printf("%01lu.\n", pi[1]);
	for (i=2; i<n-1; ++i)
		if (pi[i] <= 2048){
			printf("%04lu\n", pi[i]);
			list[i] = pi[i];
			//printf("%04lu \n", list[i]);
			gt_list[i] = 0;
			//printf("%04lu \n", gt_list[i]);
		}else{
			list[i] = 0;
			gt_list[i] = pi[i];
		}
	printf("\n");
}