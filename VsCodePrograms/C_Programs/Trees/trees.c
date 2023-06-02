#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int item;
  struct Node* left;
  struct Node* right;
} Node;

void inorderTraversal(Node* root) {
  if (!root) return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
  if (!root) return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
  if (!root) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

Node* createNode(int value) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node* insertLeft(Node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

Node* insertRight(Node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  Node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);
  printf("\n");

  printf("Preorder traversal \n");
  preorderTraversal(root);
  printf("\n");

  printf("Postorder traversal \n");
  postorderTraversal(root);
  printf("\n");

  return 0;
}
