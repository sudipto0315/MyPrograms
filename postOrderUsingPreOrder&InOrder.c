#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;

    Node* newNode = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd)
        return newNode;

    int inIndex = search(inorder, inStart, inEnd, newNode->data);

    newNode->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    newNode->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return newNode;
}

void postOrderTraversal(Node* node) {
    if (node == NULL)
        return;

    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    printf("%d ", node->data);
}

int main() {
    int n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int inorder[n], preorder[n];
    printf("Enter the inorder traversal: ");
    for (i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter the Pre-order traversal: ");
    for (i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    int preIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printf("Post-order traversal: ");
    postOrderTraversal(root);

    return 0;
}
