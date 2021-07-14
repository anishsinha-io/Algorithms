#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);
void print(int *);

int main() {
  int array[15] = {4, 11, 2, 6, 3, 14, 7, 10, 9, 5, 12, 15, 13, 1, 8};
  mergeSort(array, 0, 15);
  print(array);
}

void merge(int *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
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
  if (p < r) {
    int q = (p + r) / 2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

void print(int *arr) {
  for (int i = 0; i < 15; i++) {
    printf("%d ", arr[i]);
  }
}
