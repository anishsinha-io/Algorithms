/*************************************************************
 *
 * @author Anish Sinha
 * @date July 18, 2021
 *
 * *This program is designed to read numbers from a csv file,
 * *sort them, and then convert the sorted numbers into a
 * *balanced binary tree
 *
 * *The binary tree will be traversable.
 *
 * TODO: Create function to generate nodes for the tree
 * TODO: Create function to read the data in the csv
 * TODO: Sanitize the data in the csv
 * TODO: Create function to insert  new nodes into the tree
 *
 *
 * **********************************************************/

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILE1 "../data/numbers.txt"

int processFile(void);
int *createBuffer(int);
void print(int *, int);

// The struct below defines the structure for each individual node
typedef struct Node {
  int data;
  struct Node *leftLink;
  struct Node *rightLink;
} Node;

Node *root;

int main() {
  // This is the driver function
  root = NULL;
  int count = processFile();
  int *buffer = createBuffer(count);
  print(buffer, count);
  return 0;
}

int processFile(void) {
  FILE *file = fopen(FILE1, "r+");
  int ch;
  int count = 0;
  int delimiter = ',';
  int replacement = '_';
  while (1) {
    ch = fgetc(file);
    if (ch == EOF) {
      break;
    }

    if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
      fseek(file, ftell(file) - 1, SEEK_SET);
      fprintf(file, "%c", replacement);
    } else if (ch == '\n' || ch == ' ') {
      fseek(file, ftell(file) - 1, SEEK_SET);
      fprintf(file, "%c", delimiter);

    } else if (ch == ',') {
      ++count;
    }
  }
  fclose(file);
  return count;
}

int *createBuffer(int count) {
  FILE *file = fopen(FILE1, "r");
  int buffer[count + 1];
  int *bufferPointer = buffer;
  int number;
  int ch;
  int i = 0;
  while (1) {
    ch = fgetc(file);
    if (ch == EOF) {
      break;
    }
    if (fscanf(file, "%i", &number)) {
      buffer[i] = number;
      i++;
    }
  }
  return bufferPointer;
}

void print(int *array, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    printf("%d ", array[i]);
  }
}
