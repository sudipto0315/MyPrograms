#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

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

void inorderTraversal(struct node *root, int *array, int *index)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, array, index);
    array[*index] = root->key;
    (*index)++;
    inorderTraversal(root->right, array, index);
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

int compareBST(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return 0; // Arrays are not the same
        }
    }
    return 1; // Arrays are the same
}

int main()
{
    struct node *root1 = NULL;
    struct node *root2 = NULL;
    int n1, n2, item = 0;

    int array1[MAX_NODES];
    int index1 = 0;

    int array2[MAX_NODES];
    int index2 = 0;

    // input for first BST
    printf("For the first tree ->>");

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n1);

    printf("Enter %d elements to insert:\n", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &item);
        root1 = insert(root1, item);
    }

    // input for the second BST
    printf("For the second tree ->>");

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n2);

    printf("Enter %d elements to insert:\n", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &item);
        root2 = insert(root2, item);
    }

    // printing the inorder of the first BST
    printf("Inorder traversal of first BST: ");
    inorderTraversal(root1, array1, &index1);

    // Print the array elements
    for (int i = 0; i < index1; i++)
    {
        printf("%d ", array1[i]);
    }
    printf("\n");

    // printing the inorder of the second BST
    printf("Inorder traversal of second BST: ");
    inorderTraversal(root2, array2, &index2);

    // Print the array elements
    for (int i = 0; i < index2; i++)
    {
        printf("%d ", array2[i]);
    }
    printf("\n");

    // checking if the 2 BST's are same or not
    if (index1 != index2)
    {
        printf("The BST's are different!!\n");
    }
    else if (index1 == index2)
    {
        int size = (index1+index2)/2; //assigning 2 same values to a single varible 
        if (compareBST(array1, array2, size))
        {
            printf("The BST's are same!!\n");
        }
        else
        {
            printf("The BST's are different!!\n");
        }
    }
    return 0;
}