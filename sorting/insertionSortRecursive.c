/*******************************************************************************
 *
 * *Program that sorts an array of numbers using a recursive variation of the
 * *insertion sort algorithm.
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void insertionSortRecursive(int *, int);
void print(int *, int);

int main() {
  int array[13] = {4, 11, 2, 6, 3, 7, 10, 9, 5, 12, 13, 1, 8};
  int arraySize = sizeof(array) / sizeof(array[0]);
  insertionSortRecursive(array, arraySize);
  print(array, arraySize);
}

void insertionSortRecursive(int *A, int n) {
  if (n <= 1) {
    return;
  }
  insertionSortRecursive(A, n - 1);
  int last = A[n - 1];
  int j = n - 2;
  while (j >= 0 && A[j] > last) {
    A[j + 1] = A[j];
    j--;
  }
  A[j + 1] = last;
}

void print(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
}