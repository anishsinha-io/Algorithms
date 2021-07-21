/*******************************************************************************
 *
 * *This is a program that improves upon the bubbleSort algorithm by adding 
 * *two modifications. Firstly, it minimizes the number of passes taken over
 * *the array, and secondly, it minimizes the iterations. 
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *, int);
void swap(int *, int *);
void print(int *, int);

int main() {
  int array[] = {2, 1, 4, 6, 8, 5, 3, 7};
  int arraySize = sizeof(array) / sizeof(array[0]);
  bubbleSort(array, arraySize);
  print(array, arraySize);
  return 0;
}

void bubbleSort(int *array, int n) {
  for (int i = 0; i < n; i++) {
    int flag = 0;

    for (int j = 0; j < n - i-1; j++) {
      if (array[j] > array[j + 1]) {
        swap(&array[j], &array[j + 1]);
        flag++;
      }
    }
    if (flag == 0) {
      break;
    }
  }
}

void swap(int *x, int *y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

void print(int *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
}