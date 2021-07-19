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

#define FILE1 "../data/numbers.txt" // Define the file to read from

// The struct below defines the structure for each individual node
typedef struct Node { // Define the structure for each node. Each node has an
                      // integer value as data, a pointer to the left node and a
                      // pointer to the right node
  int data;
  struct Node *leftLink;
  struct Node *rightLink;
} Node;

// Define all functions used in the program
int processFile(void);
int *createBuffer(int);
void print(int *, int);
void merge(int *, int *, int, int *, int);
void mergeSort(int *, int);
Node *createNode(int);
Node *createTree(int *, int, int);
bool searchTree(Node *, int);

// Main method->driver function
int main() {
  int count =
      processFile(); // First we get the count of the number of commas using
                     // processFile, which also filters and sanitizes the file
  printf("%d | ", count); // Print count here to make sure everything is good
  int *buffer = createBuffer(
      count); // Create a pointer to the buffer of size count+1, which contains
              // all of the numbers read from the file
  mergeSort(buffer,
            count); // Use the mergesort algorithm to sort all of the numbers in
                    // Θ(nlgn) time.
  print(
      buffer,
      count); // Print everything in the buffer to make sure everything is good.
  Node *root = createTree(
      buffer, 0,
      count); // Define root as the returned Node from the function
              // createTree. This should return the node with the data
              // value of buffer[mid]. Everything to its left should
              // be less and everything to its right should be greater

  bool found =
      searchTree(root, 88); // Create a variable found, which returns a boolean
                            // stating whether the value was found or not
  print(buffer, count);     // Print the buffer and count here as well.
  if (found) {
    printf("Success!, Data found");
  } else {
    printf("Data not found");
  }
}

int processFile(void) {
  FILE *file = fopen(FILE1, "r+"); // Open the file in read-and-edit mode.
  // define variables
  int ch;
  int count = 0;
  int delimiter = ',';
  int replacement = ' ';
  // while true
  while (1) {
    ch = fgetc(file); // ch is the next character in the file
    if (ch == EOF) {  // if ch is EOF, break.
      break;
    }

    if (ch >= 'a' && ch <= 'z' ||
        ch >= 'A' && ch <= 'Z') { // Sanitize the file of all letters, replace
                                  // some characters, and add delimiters
      fseek(file, ftell(file) - 1, SEEK_SET);
      fprintf(file, "%c", replacement);
    } else if (ch == '\n' || ch == ' ') {
      fseek(file, ftell(file) - 1, SEEK_SET);
      fprintf(file, "%c", delimiter);

    } else if (ch == ',') { // count the number of commas
      ++count;
    }
  }
  fclose(file); // close the file
  return count; // return the integer value of the count
}

int *createBuffer(int count) {    // Function to create a buffer to store all of
                                  // the integer values in the file
  FILE *file = fopen(FILE1, "r"); // Open the file in read-only mode
  int *buffer = (int *)malloc(
      sizeof(int) *
      (count + 1)); // Define a pointer to the buffer. Allocate memory for it.
  // Define some variables to be used
  int number;
  int ch;
  int i = 0;
  while (1) { // While true

    if (fscanf(file, "%i", &number) == 1) {
      buffer[i] = number;
      printf("%d ", buffer[i]);
      ++i;
    }
    ch = fgetc(file); // ch is the next character in the file
    if (ch == EOF) {  // If the next character is the end-of-file
      break;          // break
    }
  }
  fclose(file);  // close the file
  return buffer; // return the buffer, which is a pointer to the array that
                 // holds all of the data
}

void print(int *array,
           int arraySize) { // Function to print everything in the buffer.
                            // Mostly used for debugging purposes
  for (int i = 0; i <= arraySize; i++) {
    printf("%d ", array[i]);
  }
}

void merge(int *A, int *L, int leftSize, int *R,
           int rightSize) { // Merging two sorted arrays. Called in mergeSort
  int i = 0, j = 0, k = 0;
  while (i < leftSize && j < rightSize) { // Self explanatory. See Chapter 2 of
                                          // CLRS - MIT for details
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

void mergeSort(int *A,
               int n) { // Recursively merge and sort two arrays. Again, self
                        // explanatory. See chapter 2 of CLRS - MIT for details
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

Node *createTree(int *buffer, int low,
                 int high) { // Function to create the binary tree
  if (low > high) {          // If the low is greater than the high, return NULL
    return NULL;
  }

  int mid = (high + low) / 2; // Mid is the average of the high and low indexes
  Node *root = createNode(buffer[mid]); // Create root.
  root->leftLink =
      createTree(buffer, low, mid - 1); // Define root's left and right link
  root->rightLink = createTree(
      buffer, mid + 1,
      high);   // Recursively define those subtrees' left and right link as well
  return root; // At the end of the recursion, return root, which holds the
               // value at buffer[mid]
}

bool searchTree(Node *root, int data) { // Function to search the binary tree
  if (root == NULL) {                   // If root is null, return false
    return false;
  } else if (root->data == data) { // If the data value within root matches the
                                   // data passed into the function, return true
    return true;
  } else if (data <= root->data) { // Else if data is less than that value,
                                   // recursively run search on the left subtree
    return searchTree(root->leftLink, data);
  } else { // Same as above but for the right subtree.
    return searchTree(root->rightLink, data);
  }
}
