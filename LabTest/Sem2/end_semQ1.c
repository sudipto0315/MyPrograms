#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

// Inorder traversal
void inorderTraversal(struct node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}
// Inorder traversal using array
void inorderArray(struct node *root, int *array, int *index)
{
    if (root == NULL)
        return;
    inorderArray(root->left, array, index);
    array[*index] = root->key;
    (*index)++;
    inorderArray(root->right, array, index);
}

// Create a new Node
struct node *createNode(int value)
{
    struct node *newNode = malloc(sizeof(struct node));
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

// Quick Sort (Start)
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int partition(int a[], int l, int h)
{
    int pivot = a[h];
    int i = (l - 1);
    for (int j = l; j <= h - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[h]);
    return (i + 1);
}

void quickSort(int a[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(a, l, h);
        quickSort(a, l, j - 1);
        quickSort(a, j + 1, h);
    }
}
// Quick Sort(end)

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
    inorderTraversal(root);
    printf("\n");
    inorderArray(root, array, &index); // we get the inorder array and its size in array[] and index
    // sorting the inorder array
    quickSort(array, 0, index - 1);
    printf("The minimum value in the tree is = %d", array[0]);

    // Free the memory for the binary tree
    freeTree(root);

    printf("\n");

    return 0;
}