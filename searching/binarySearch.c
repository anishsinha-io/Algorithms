/*******************************************************************************
 *
 * *This is a simple algorithm to perform a binary search on a linked list of
 * *nodes.
 *
 * @author Anish Sinha, July 13, 2021
 *
 * ****************************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *leftLink;
  struct Node *rightLink;
} Node;

Node *root;

void createTree(int *, int);
Node *getNewNode(int);
Node *insert(Node *, int);
bool search(Node *, int);

int main() {
  root = NULL;

  int array[] = {15, 10, 20, 8, 12, 17, 25};
  int arraySize = sizeof(array) / sizeof(array[0]);
  createTree(array, arraySize);

  if (search(root, 8)) {
    printf("Data found");
  } else {
    printf("Data not found");
  }
}

Node *getNewNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->leftLink = NULL;
  newNode->rightLink = NULL;
  return newNode;
}

Node *insert(Node *root, int data) {
  if (root == NULL) {
    root = getNewNode(data);
  } else if (data <= root->data) {
    root->leftLink = insert(root->leftLink, data);
  } else {
    root->rightLink = insert(root->rightLink, data);
  }
  return root;
}

bool search(Node *root, int data) {
  if (root == NULL) {
    return false;
  } else if (root->data == data) {
    return true;
  } else if (data < root->data) {
    return search(root->leftLink, data);
  } else {
    return search(root->rightLink, data);
  }
}

void createTree(int *array, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    root = insert(root, array[i]);
  }
}
