/* Print pi to n decimal places (default 1000): pi n */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(unsigned short* xp, unsigned short* yp);
void bubbleSort(unsigned short arr[], int n);
void printArray(unsigned short arr[], int size);

/* Print pi as an array of n digits in base 10000 */
void print(unsigned short *pi, unsigned short *list, int n) {
  int i;
  //printf("%d", pi[0]);
  //printf("%d.\n", pi[1]);
  for (i=2; i<n-1; ++i)
    if (pi[i] <= 2048){
	list[i] = pi[i];
      printf("%04d:%04d\n", pi[i],i);
    } else {
      //printf("%04d-%d\n", pi[i],i);
      printf("%04d\n", pi[i]);
    }
  //bubbleSort(pi, sizeof(&pi));
  printf("\n");
  // bubbleSort(pi, n);
  // printf("Sorted array: \n");
  printArray(list, n);
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
void bubbleSort(unsigned short arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

/* Function to print an array */
void printArray(unsigned short arr[], int size)
{
	int i;
	for (i = 2; i < size-1; i++)
		printf("%04d ", arr[i]);
	printf("\n");
}

int main(int argc, char** argv) {
  int n = argc > 1 ? (atoi(argv[1])+3)/4+3 : 253;  /* number of pi digits */
  unsigned short *pi   = (unsigned short*) malloc(n * sizeof(unsigned short));
  unsigned short *list = (unsigned short*) malloc(n * sizeof(unsigned short));
  div_t d;
  int i, j, t;

  /* pi = 4  */
  memset(pi, 0, n*sizeof(unsigned short));
  pi[1]=4;

  /* for i = B down to 1 */
  for (i=(int)(3.322*4*n); i>0; --i) {

    /* pi *= i; */
    t = 0;
    for (j=n-1; j>=0; --j) {  /* pi *= i; */
      t += pi[j] * i;
      pi[j] = t % 10000;
      t /= 10000;
    }

    /* pi /= (2*i+1) */
    d.quot = d.rem = 0;
    for (j=0; j<n; ++j) {  /* pi /= 2*i+1; */
      d = div(pi[j]+d.rem*10000, i+i+1);
      pi[j] = d.quot;
    }

    /* pi += 2 */
    pi[1] += 2;
  }

  print(pi, list, n);

  // bubbleSort(pi, n);
  // printf("Sorted array: \n");
  // printArray(pi, n);

  return 0;
}

