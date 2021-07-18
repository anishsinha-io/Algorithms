/*******************************************************************************
 *
 * *This is a program that improves upon the insertionSort algorithm by adding
 * *the capability to search for the location that an item needs to be
 * *inserted at using a binary search algorithm.
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/
#include <stdio.h>

void insertionSort(int *, int);
int binarySearch(int *, int, int, int);
void print(int *, int);

int main() {
  int array[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
  int arraySize = sizeof(array) / sizeof(array[0]);
  insertionSort(array, arraySize);
  print(array, arraySize);
}

void insertionSort(int *array, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    int key = array[i];
    int j = i - 1;
    int loc = binarySearch(array, key, 0, j);
    while (j >= loc) {
      array[j + 1] = array[j];
      j--;
    }
    array[j + 1] = key;
  }
}

int binarySearch(int *array, int key, int low, int high) {
  if (high <= low) {
    return (key > array[low]) ? (low + 1) : low;
  }
  int mid = (high + low) / 2;
  if (key == array[mid]) {
    return mid + 1;
  }
  if (key > array[mid]) {
    return binarySearch(array, key, mid + 1, high);
  }
  return binarySearch(array, key, low, mid - 1);
}

void print(int *array, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d ", array[i]);
  }
}