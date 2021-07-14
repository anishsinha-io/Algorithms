#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *, int, int, int);
void print(int *, int);

int main() {
  int array[15] = {4, 11, 2, 6, 3, 14, 7, 10, 9, 2, 12, 15, 13, 1, 8};
  int *arr = array;
  int arraySize = sizeof(array) / sizeof(array[0]);
  int p = 0, q = arraySize / 2, r = arraySize;
  merge(arr, p, q, r);
  for (int i = 0; i < r; i++) {
    printf("%d ", array[i]);
  }
}

void merge(int *arr, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;

  int subArray1[q];
  for (int i = p; i < n1; i++) {
    subArray1[i] = arr[i];
  }
  int subArray2[q];
  for (int j = 1; j < n2; j++) {
    subArray2[j] = arr[q + j];
  }
  int i, j = 1;
  for (int k = 0; k < r; k++) {
    if (subArray1[i] < subArray2[i]) {
      arr[k] = subArray1[i];
      i++;
    } else {
      arr[k] = subArray2[j];
      j++;
    }
  }
}
