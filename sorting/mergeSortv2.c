/*******************************************************************************
 *
 * *This is an improved mergeSort algorithm that does not use sentinels
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void mergeSort(int *, int);
void merge(int *, int *, int, int *, int);
void print(int *, int);

int main() {
  int A[] = {2, 4, 1, 6, 8, 5, 9, 3, 7};
  int arraySize = sizeof(A) / sizeof(A[0]);
  mergeSort(A, arraySize);
  print(A, arraySize);
}

void mergeSort(int *A, int n) {
  if (n < 2) {
    return;
  }

  int mid = n / 2;
  int L[mid];
  int R[n - mid];

  for (int i = 0; i < mid; i++) {
    L[i] = A[i];
  }
  for (int j = mid; j < n; j++) {
    R[j - mid] = A[j];
  }

  int leftSize = mid;

  int rightSize = n - mid;
  mergeSort(L, leftSize);
  mergeSort(R, rightSize);

  merge(A, L, leftSize, R, rightSize);
}

void merge(int *A, int *L, int leftSize, int *R, int rightSize) {

  int i = 0;
  int j = 0;
  int k = 0;
  while (i < leftSize && j < rightSize) {
    if (L[i] < R[j]) {
      A[k] = L[i];

      i++;
    } else {
      A[k] = R[j];

      j++;
    }
    k++;
  }
  while (i < leftSize) {
    A[k] = L[i];
    i++;
    k++;
  }
  while (j < rightSize) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void print(int *A, int n) {
  for (int i = 0; i < n; i++) {
    printf("[%d] ", A[i]);
  }
}