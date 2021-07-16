/*******************************************************************************
 *
 * *This is a simple algorithm to perform a basic linear search
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int A[5] = {1, 2, 3, 4, 5};
  int v = 3;
  for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++) {
    if (A[i] == v) {
      return true;
    } else {
      continue;
    }
  }
  return false;
}