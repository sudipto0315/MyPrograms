#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

struct Node* searchElement(struct Node* root, int target) {
    if (root == NULL || root->value == target) {
        return root;
    }
    struct Node* leftResult = searchElement(root->left, target);
    if (leftResult != NULL) {
        return leftResult;
    }
    struct Node* rightResult = searchElement(root->right, target);
    return rightResult;
}

int main() {
    struct Node* root = NULL;
    int n, value, target;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of nodes:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Enter the value to search: ");
    scanf("%d", &target);
    struct Node* result = searchElement(root, target);
    if (result != NULL) {
        printf("Element found in the binary tree.\n");
    } else {
        printf("Element not found in the binary tree.\n");
    }
    return 0;
}
