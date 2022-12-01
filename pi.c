/* Print pi to n decimal places (default 1000): pi n */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned short chunk;
	unsigned short index;
} chunk_index;

void swap(unsigned short* xp, unsigned short* yp);
void bubbleSort(unsigned short arr[], unsigned short arr2[], int n);
void printArray(unsigned short arr[], int size);
void populate_chunk_index(unsigned short arr[], chunk_index ci[], int size);

/* Print pi as an array of n digits in base 10000 */
void print(unsigned short *pi, unsigned short *list, unsigned short *gt_list, int n) {
  int i;
  printf("%d", pi[0]);
  printf("%d.\n", pi[1]);
  for (i=2; i<n-1; ++i)
    if (pi[i] <= 2048){
        list[i] = pi[i];
        gt_list[i] = 0;
    }else{
        list[i] = 0;
        gt_list[i] = pi[i];
    }
  printf("\n");
}

/* Compute pi to B bits precision by the Spigot algorithm given by
Rabinowitz and Wagon, Am. Math. Monthly, March 1995, 195-203.

   pi = 4;
   for (i = B; i>0; --i)
     pi = 2 + pi * i / (2*i+1)

pi is represented by a base 10000 array of digits with 2 digits before
the decimal point (pi[0], pi[1]), and one extra digit (pi[n-1]) at
the end to allow for roundoff error, which is not printed.  Note that a
base 10 digit is equivalent to log(10)/log(2) = 3.322 bits.

For shorter versions, see
http://www1.physik.tu-muenchen.de/~gammel/matpack/html/Mathematics/Pi.html
http://numbers.computation.free.fr/Constants/TinyPrograms/tinycodes.html

and for an explanation of how they work, see
Unbounded Spigot Algorithms for the Digits of Pi,
Jeremy Gibbons, University of Oxford, 2004,
http://web.comlab.ox.ac.uk/oucl/work/jeremy.gibbons/publications/spigot.pdf

*/

void swap(unsigned short* xp, unsigned short* yp)
{
	unsigned short temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort
void bubbleSort(unsigned short arr[], unsigned short arr2[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j],  &arr[j + 1]);
				swap(&arr2[j], &arr2[j + 1]);
}

/* Function to print an array */
void printArray(unsigned short arr[], int size)
{
	int i;
	for (i = 2; i < size-1; i++)
		//printf("%04d:     ", arr[i]);
		printf("%04d:%04d ", arr[i], i);
	printf("\n");
}
void populate_chunk_index(unsigned short arr[], chunk_index ci[], int size)
{
	int i;
	for (i = 2; i < size-1; i++){
		ci[i].chunk = arr[i];
		ci[i].index = i;
		//printf("i=%04d\n",i);
		//printf("arr[i]=%04d\n", arr[i]);
		//printf("%04d:%04d:%04d\n", ci[i].chunk, ci[i].index, size);
		printf("%04d:%04d\n", ci[i].chunk, ci[i].index);
		};

}

int main(int argc, char** argv) {

  int n = argc > 1 ? (atoi(argv[1])+3)/4+3 : 253;  /* number of pi digits */
  unsigned short *pi       = (unsigned short*) malloc(n * sizeof(unsigned short));
  unsigned short *list     = (unsigned short*) malloc(n * sizeof(unsigned short));
  unsigned short *gt_list  = (unsigned short*) malloc(n * sizeof(unsigned short));

  chunk_index *chunk_list  = (chunk_index*)    malloc(n * sizeof(chunk_index));

  div_t d;
  int i, j, t1, t2, t3;

  /* pi = 4  */
  memset(pi,      0, n*sizeof(unsigned short));
  memset(list,    0, n*sizeof(unsigned short));
  memset(gt_list, 0, n*sizeof(unsigned short));
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
      pi[j]      = t1 % 10000;
      list[j]    = t2 % 10000;
      gt_list[j] = t3 % 10000;
      t1 /= 10000;
      t2 /= 10000;
      t3 /= 10000;
    }

    /* pi /= (2*i+1) */
    d.quot = d.rem = 0;
    for (j=0; j<n; ++j) {  /* pi /= 2*i+1; */
      d = div(pi[j]+d.rem*10000, i+i+1);
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
  // printf("Sorted array: \n");

  printArray(pi,   n);
  //printArray(list, n);
  //printArray(gt_list, n);
  populate_chunk_index(pi, chunk_list, n);

  printf("\n");

  return 0;
}

