#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getArraySize(int *);

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};
  int arraySize = getArraySize(array);
  for (int i = 1; i < 6; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
  for (int i = 0; i < 6; i++) {
    printf("%d ", array[i]);
  }
}

int getArraySize(int *array) {
  int arraySize = sizeof(*array) / sizeof(array[0]);
  return arraySize;
}