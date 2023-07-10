#include <stdio.h>
#include <stdlib.h>
struct node
{
    int key;
    struct node *left;
    struct node *right;
};

void inorderTraversal(struct node *root)
{
    if (root == NULL)
    {
        printf("None");
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

// Create a new Node
struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert on the left of the node
struct node *insertLeft(struct node *root, int value)
{
    root->left = createNode(value);
    return root->left;
}

// Insert on the right of the node
struct node *insertRight(struct node *root, int value)
{
    root->right = createNode(value);
    return root->right;
}

// Build the binary tree
struct node *buildTree()
{
    int value = 0;
    struct node *root = NULL;

    printf("Enter node value (-1 to stop): ");
    scanf("%d", &value);

    if (value != -1)
    {
        root = createNode(value);

        printf("Enter left child of %d\n", value);
        root->left = buildTree();

        printf("Enter right child of %d\n", value);
        root->right = buildTree();
    }

    return root;
}

// Free the memory for the binary tree
void freeTree(struct node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Finding the minimum in the Binary Tree
int findMinimum(struct node *root)
{
    if (root == NULL)
        return -1;

    int leftMin = findMinimum(root->left);
    int rightMin = findMinimum(root->right);

    int minimum = root->key;

    if (leftMin < minimum)
        minimum = leftMin;
    if (rightMin < minimum)
        minimum = rightMin;

    return minimum;
}

int main()
{
    struct node *root = NULL;

    printf("Build the binary tree\n");
    root = buildTree();

    printf("\nInorder traversal:\n");
    inorderTraversal(root);
    printf("\n");

    printf("The minimum value in the tree is = %d\n", findMinimum(root));

    // Free the memory for the binary tree
    freeTree(root);

    return 0;
}
