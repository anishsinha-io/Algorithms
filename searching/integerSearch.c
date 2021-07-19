/*******************************************************************************
 *
 * *This is an algorithm that takes a value and determines whether there are
 * *two values in the array that sum to the given value.
 *
 * *The time complexity of this algorithm is O(nlgn) because searching the
 * *array can be completed in O(lgn) time using a binary search but
 * *in the worst case, all elements will have to be traversed at least once,
 * *which is O(n)time complexity.
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool binarySearch(int *, int, int, int);
bool complementExists(int *, int, int);

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arraySize = sizeof(array) / sizeof(array[0]);
  bool exists = complementExists(array, arraySize, 18);
  if (exists) {
    printf("Exists");
  } else {
    printf("Does not exist");
  }
}

// function that performs a binary search. It takes a pointer to an array, a
// value, a lower bound, and an upper bound as input
bool binarySearch(int *array, int val, int low, int high) {
  int mid = (high + low) / 2;
  int root = array[mid];
  if (low == high) {
    return false;
  }
  if (root == val) {
    return true;
  } else if (root <= val) {
    return binarySearch(array, val, mid + 1, high);
  } else {
    return binarySearch(array, val, 0, mid);
  }
  return false;
}

// Determines whether two complements exist in the array that sum to val
bool complementExists(int *array, int arraySize, int val) {
  for (int i = 0; i < arraySize; i++) {
    int key = val - i;
    if (binarySearch(array, key, i, arraySize) == true) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}
