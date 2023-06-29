#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node
{
    int item;
    struct node *left;
    struct node *right;
};

// Inorder traversal
void inorderTraversal(struct node *root, int *array, int *index)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, array, index);
    array[*index] = root->item;
    (*index)++;
    inorderTraversal(root->right, array, index);
}

// Create a new Node
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->item = value;
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
    int value=0;
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

int isAscending(int arr[], int index)
{
    for (int i = 1; i < index; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0; // Not ascending
        }
    }
    return 1; // Ascending
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


int main()
{
    struct node *root = NULL;

    printf("Build the binary tree\n");
    root = buildTree();

    int array[MAX_NODES];
    int index = 0;

    printf("\nInorder traversal:\n");
    inorderTraversal(root, array, &index);

    // Print the array elements
    for (int i = 0; i < index; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    if (isAscending(array, index))
    {
        printf("The tree is a Binary Search Tree.\n");
    }
    else
    {
        printf("The tree is not a Binary Search Tree.\n");
    }

    // Free the memory for the binary tree
    freeTree(root);

    printf("\n");

    return 0;
}
