#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int);
void swap(int *, int *);
void print(int*, int);

int main() {
  int array[8] = {2, 1, 4, 6, 8, 5, 3, 7};
  int arraySize = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, arraySize);
  print(array, arraySize);
  return 0;
}

void bubbleSort(int *array, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    for (int j=arraySize-1; j >= 0; j--) {
      if (array[j] < array[j - 1]) {
        swap(&array[j], &array[j-1]);
      }
    }
  }
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void print(int* array, int arraySize){
    for(int i=0;i<arraySize;i++){
        printf("%d ",array[i]);
    }
}