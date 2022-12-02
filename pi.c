/* Print pi to n decimal places (default 1000): pi n */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "print_pi.c"
#include "print_array.c"
#include "populate_chunk_index.c"
#include "bubble_sort.c"
#include "constants.c"

#define BASE 1000

void swap(unsigned long* xp, unsigned long* yp);
void bubble_sort(unsigned long arr[], unsigned long arr2[], int n);
void print_array(unsigned long arr[], int size);
void populate_chunk_index(unsigned long arr[], chunk_index ci[], int size);

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

int main(int argc, char** argv) {

  int n = argc > 1 ? (atoi(argv[1])+3)/4+3 : 253;  /* number of pi digits */
  unsigned long *pi       = (unsigned long*) malloc(n * sizeof(unsigned long));
  unsigned long *list     = (unsigned long*) malloc(n * sizeof(unsigned long));
  unsigned long *gt_list  = (unsigned long*) malloc(n * sizeof(unsigned long));

  chunk_index *chunk_list  = (chunk_index*)    malloc(n * sizeof(chunk_index));

  div_t d;
  int i, j, t1, t2, t3;

  /* pi = 4  */
  memset(pi,      0, n*sizeof(unsigned long));
  memset(list,    0, n*sizeof(unsigned long));
  memset(gt_list, 0, n*sizeof(unsigned long));
  pi[1]=4;
  list[1]=4;
  gt_list[1]=4;

  /* for i = B down to 1 */
  for (i=(int)(3.322*4*n); i>0; --i) {

    /* pi *= i; */
    t1 = 0;
    t2 = 0;
    t3 = 0;
    for (j=n-1; j>=0; --j) {  /* pi *= i; */
      t1 += pi[j] * i;
      t2 += list[j] * i;
      t3 += gt_list[j] * i;
      pi[j]      = t1 % BASE;
      list[j]    = t2 % BASE;
      gt_list[j] = t3 % BASE;
      t1 /= BASE;
      t2 /= BASE;
      t3 /= BASE;
    }

    /* pi /= (2*i+1) */
    d.quot = d.rem = 0;
    for (j=0; j<n; ++j) {  /* pi /= 2*i+1; */
      d = div(pi[j]+d.rem*BASE, i+i+1);
      pi[j]      = d.quot;
      list[j]    = d.quot;
      gt_list[j] = d.quot;
    }

    /* pi += 2 */
    pi[1] += 2;
    list[1] += 2;
    gt_list[1] += 2;
  }

  //bubbleSort(pi, list, n);
  //printf("Sorted array: \n");

  print_array(pi,   n);
  print_array(list, n);
  print_array(gt_list, n);
  populate_chunk_index(pi, chunk_list, n);
  print(pi, list, gt_list, n);
  //print_pi(pi, list, gt_list, n);

  printf("\n");

  return 0;
}

