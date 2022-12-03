#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Print pi as an array of n digits in base BASE */
void print_pi(unsigned long *pi, int n) {

	int i;
	printf("print\n");
	printf("\n");
	//printf("%lu", pi[0]);
	printf("%1lu.\n", pi[1]);
	for (i=2; i<n-1; ++i)
		if (pi[i] <= 2048){
			printf("%04lu\n", pi[i]);
		}else{}
	printf("\n");
}
