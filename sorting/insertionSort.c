/*******************************************************************************
 *
 * *Program that performs the insertion sort algorithm to sort an array of
 * *numbers in place.
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3}; // Initializes an array of unsorted
                                     // integers

  int arraySize =
      sizeof(array) / sizeof(array[0]); // Calculates the size of the array
  for (int i = 0; i < arraySize;
       i++) {           // Iterates from the start of the array to the end
    int key = array[i]; // key, a temporary variable, is initialized to be the
                        // array element of the current iteration
    int j = i - 1;      // Initializes a variable j to act as a second index
    while (
        j >= 0 &&
        array[j] >
            key) { // while index j is greater than zero and the value
                   // of the array at that index is greater than the
                   // value stored in the variable key,
                   //? The elements can be sorted in decreasing order simply by
                   //? changing '>' to '<'. This is trivial because all we are
                   //? doing is changing the orientation the element will be
                   //? placed relative to the integer it is being compared to

      array[j + 1] = array[j]; // Set the array value at index j+1 equal to the
                               // value at index j
      j--;                     // decrement the index variable
    }
    array[j + 1] =
        key; // The new key value is the value of the array at index j+1
  }
  for (int i = 0; i < arraySize; i++) { // print the array elements
    printf("%d ", array[i]);
  }
}
