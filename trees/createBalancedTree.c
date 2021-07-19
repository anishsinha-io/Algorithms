/*************************************************************
 *
 * @author Anish Sinha
 * @date July 18, 2021
 *
 * *This program is designed to read numbers from a file,
 * *sort them, and then convert the sorted numbers into a
 * *balanced binary tree
 *
 *
 * **********************************************************/

#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILE1 "../data/numbers.txt"

// The struct below defines the structure for each individual node
typedef struct Node {
  int data;
  struct Node *leftLink;
  struct Node *rightLink;
} Node;

int processFile(void);
int *createBuffer(int);
void print(int *, int);
void merge(int *, int *, int, int *, int);
void mergeSort(int *, int);
Node *createNode(int);
Node *createTree(int *, int, int);
bool searchTree(Node *, int);

int main() {
  // This is the driver function
  int count = processFile();
  printf("%d ", count);
  int *buffer = createBuffer(count);
  mergeSort(buffer, count);
  print(buffer, count);
  Node *root = createTree(buffer, 0, count);

  bool found = searchTree(root, 49);
  print(buffer, count);
}

int processFile(void) {
  FILE *file = fopen(FILE1, "r+");
  int ch;
  int count = 0;
  int delimiter = ',';
  int replacement = ' ';
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
  int *buffer = malloc(count + 2);
  int *bufferPointer = buffer;
  int number;
  int ch;
  int i = 0;
  while (1) {
    ch = fgetc(file);
    if (ch == EOF) {
      break;
    }
    if (fscanf(file, "%i", &number) == 1) {
      buffer[i] = number;
      printf("%d ", buffer[i]);
      ++i;
    }
  }
  fclose(file);
  return bufferPointer;
}

void print(int *array, int arraySize) {
  for (int i = 0; i <= arraySize; i++) {
    printf("%d ", array[i]);
  }
}

void merge(int *A, int *L, int leftSize, int *R, int rightSize) {
  int i = 0, j = 0, k = 0;
  while (i < leftSize && j < rightSize) {
    if (L[i] < R[j]) {
      A[k] = L[i];
      i++;

    } else {
      A[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < leftSize) {
    A[k] = L[i];
    i++;
    k++;
  }
  while (j < rightSize) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int *A, int n) {
  if (n < 2) {
    return;
  }
  int leftSize = floor(n / 2);
  int rightSize = n - leftSize;
  int L[leftSize];
  int R[rightSize];
  for (int i = 0; i < leftSize; i++) {
    L[i] = A[i];
  }
  for (int j = leftSize; j < n; j++) {
    R[j - leftSize] = A[j];
  }
  mergeSort(L, leftSize);
  mergeSort(R, rightSize);
  merge(A, L, leftSize, R, rightSize);
}

Node *createNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->leftLink = NULL;
  newNode->rightLink = NULL;
  return newNode;
}

Node *createTree(int *buffer, int low, int high) {
  if (low > high) {
    return NULL;
  }

  int mid = (high + low) / 2;
  Node *root = createNode(buffer[mid]);
  root->leftLink = createTree(buffer, low, mid - 1);
  root->rightLink = createTree(buffer, mid + 1, high);
  return root;
}

bool searchTree(Node *root, int data) {
  if (root == NULL) {
    printf("data not found");
    return false;
  } else if (root->data == data) {
    printf("data found");
    return true;
  } else if (data <= root->data) {
    return searchTree(root->leftLink, data);
  } else {
    return searchTree(root->rightLink, data);
  }
}
