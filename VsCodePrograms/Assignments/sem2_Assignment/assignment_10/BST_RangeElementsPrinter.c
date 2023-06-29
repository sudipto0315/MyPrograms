#include <stdio.h>
#include <stdlib.h>
int z, n = 1;
int inorderArray[1];

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

int inorder(struct node *root, int inorderArray[])
{
    if (root != NULL)
    {
        inorder(root->left, inorderArray);
        printf("%d ", root->key);
        inorderArray[z++] = root->key;
        inorder(root->right, inorderArray);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

int main()
{
    struct node *root = NULL;
    int item = 0;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    int inorderArray[n];

    printf("Enter %d elements to insert:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insert(root, item);
    }
    printf("The Complete Inorder Traversal is: ");
    inorder(root, inorderArray);
    printf("\nEnter the range to print the elements:\n");
    printf("Enter the starting point: ");
    int k1;
    scanf("%d", &k1);

    printf("Enter the ending point: ");
    int k2;
    scanf("%d", &k2);

    // Print the inorder array elements in the given range k1 to k2
    for (int i = k1; i <= k2; i++)
    {
        printf("%d ", inorderArray[i]);
    }
    printf("\n");

    return 0;
}
