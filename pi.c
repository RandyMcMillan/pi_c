/* Print pi to n decimal places (default 1000): pi n */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//
#include "constants.c"
//
#include "print.c"
#include "print_pi.c"
#include "print_array.c"
//
#include "bubble_sort.c"
#include "populate_chunk_index.c"
//
#define BASE 10000

//pi.h
void swap(unsigned long* xp, unsigned long* yp);
void bubble_sort(unsigned long arr[], unsigned long arr2[], int n);
void print_array(unsigned long arr[], int size);
void print_array2(unsigned long arr1[], unsigned long arr2[], int size);
void print_pi(unsigned long *pi, int n);
void populate_chunk_index(unsigned long arr[], chunk_index ci[], int size);
//pi.h

int main(int argc, char** argv) {

  size_t counter = 0;
  int n                   = argc > 1 ? (atoi(argv[1])+3)/4+3 : 253;
  int base                = argc > 2 ? (atoi(argv[2])) : BASE;
  unsigned long *pi       = (unsigned long*) malloc(n * sizeof(unsigned long));
  unsigned long *list     = (unsigned long*) malloc(n * sizeof(unsigned long));
  unsigned long *gt_list  = (unsigned long*) malloc(n * sizeof(unsigned long));
  chunk_index *chunk_list = (chunk_index*)   malloc(n * sizeof(chunk_index));

  for (counter = 1; counter < argc; counter++)
    {

        //printf("argv[%zu] = %s\n", counter, argv[counter]);
        if (argv[counter][0] == '-')
        {
             if (argv[counter][1] == 'i')
             {
                 printf("i");
             }
             if (argv[counter][1] == 'l')
             {
                 printf("l");
             }
             if (argv[counter][1] == 'w')
             {
                 printf("w");
             }
             if (argv[counter][1] == '-')
             {
                 printf("-");
             }
             else
             {
                 printf("Invalid option.");
                 return 2;
             }
        }
        else
        {
           printf("");
        }
    }

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
      pi[j]      = t1 % base;
      list[j]    = t2 % base;
      gt_list[j] = t3 % base;
      t1 /= base;
      t2 /= base;
      t3 /= base;
    }

    /* pi /= (2*i+1) */
    d.quot = d.rem = 0;
    for (j=0; j<n; ++j) {  /* pi /= 2*i+1; */
      d = div(pi[j]+d.rem*base, i+i+1);
      pi[j]      = d.quot;
      list[j]    = d.quot;
      gt_list[j] = d.quot;
    }

    /* pi += 2 */
    pi[1] += 2;
    list[1] += 2;
    gt_list[1] += 2;
  }

  //bubble_sort(pi, list, n);
  //printf("Sorted array: \n");

  print_array(pi,          n);
  // bubble_sort(pi, list,    n);
  print_array(list,        n);
  print_array(gt_list,     n);
  //
  // print_array2(pi,list,    n);
  // print_array2(pi,gt_list, n);
  // print_pi(pi, list, gt_list, n);
  // populate_chunk_index(pi, chunk_list, n);
  // print(pi, list, gt_list, n);

  //printf("\n");

  return 0;
}

