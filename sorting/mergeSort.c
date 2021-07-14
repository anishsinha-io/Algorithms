/*******************************************************************************
 *
 * *Program that sorts an array of numbers using a merge-sort algorithm, which
 * *is O(n) efficient. It is better than insertion sort for this reason.
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *, int, int, int); // Declare functions to be used
void mergeSort(int *, int, int);
void print(int *);

int main() {
  int array[13] = {4, 11, 2,  6,  3, 7, 10,
                   9, 5,  12, 13, 1, 8}; // Initialize an array
  mergeSort(array, 0, 12);               // Call mergeSort
  print(array);                          // Print the result
  return 0;
}

void merge(int *A, int p, int q, int r) {
  int n1 = q - p + 1; // p, q, and r are defined in the closure of mergeSort
  int n2 = r - q;     // n1 is
  int i, j, k;
  int L[n1 + 1];
  int R[n2 + 1];
  for (i = 0; i < n1; i++) {
    L[i] = A[p + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = A[q + j + 1];
  }
  L[n1] = 1000;
  R[n2] = 1000;
  i = 0, j = 0;
  for (k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int *A, int p, int r) {
  if (p < r) {                  // If p is less than r
    int q = floor((p + r) / 2); // Define q as the average of p and q
    mergeSort(A, p, q);         // perform mergeSort on
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

void print(int *arr) {
  for (int i = 0; i < 13; i++) {
    printf("%d ", arr[i]);
  }
}
