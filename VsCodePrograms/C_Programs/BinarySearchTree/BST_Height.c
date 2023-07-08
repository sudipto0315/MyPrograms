#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
struct node
{
    int key;
    struct node *left, *right;
};

struct node *queue[500];
int front = -1;
int rear = -1;

void enqueue(struct node *data)
{
    if (front == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

struct node *dequeue()
{
    struct node *data = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front++;

    return data;
}

int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
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

void levelOrderTrav(struct node *root)
{
    enqueue(root);
    enqueue(NULL);
    while (!isEmpty())
    {
        struct node *temp = dequeue();
        if (temp == NULL)
        {
            printf("\n");
            if (!isEmpty())
                enqueue(NULL);
        }
        else
        {
            printf("%d ", temp->key);
            if (temp->left)
                enqueue(temp->left);

            if (temp->right)
                enqueue(temp->right);
        }
    }
}
int height(struct node *root)
{
    if(root==0)
    return 0;
    return (int)fmax(height(root->left),height(root->right))+1;
}

int main()
{
    struct node *root = NULL;
    int n, item;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements to insert:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        root = insert(root, item);
    }

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    levelOrderTrav(root);
    printf("The height of the tree is: %d\n",height(root)-1);    
    return 0;
}