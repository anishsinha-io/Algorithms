/*******************************************************************************
 *
 * *Alternative program to sort an array of numbers using insertion sort
 * *recursively
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void insert(int *, int);
void recursiveInsertionSort(int *, int);
void print(int *, int);

int main() {
  int array[13] = {4, 11, 2, 6, 3, 7, 10, 9, 5, 12, 13, 1, 8};
  int arraySize = sizeof(array) / sizeof(array[0]);
  recursiveInsertionSort(array, arraySize);
  print(array, arraySize);
}

void insert(int *A, int k) {
  int key = A[k];
  int index = k - 1;
  while (index >= 0 && A[index] > key) {

    A[index + 1] = A[index];
    index--;
  }
  A[index + 1] = key;
}

void recursiveInsertionSort(int *A, int n) {
  if (n > 1) {
    recursiveInsertionSort(A, n - 1);
    insert(A, n);
  }
}

void print(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", A[i]);
  }
}