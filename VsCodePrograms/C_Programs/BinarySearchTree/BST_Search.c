#include <stdio.h>
#include <stdlib.h>

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

struct node *search(struct node *root, int data){
    if (root == NULL)
        return NULL;
    if (data < root->key)
        return search(root->left,data);
    else if (data > root->key)
        return search(root->right,data);
    return root;
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
    printf("enter the element to search in the BST: ");
    int searchItem;
    scanf("%d",&searchItem);
    struct node *result = search(root,searchItem);
    if (result != NULL)
        printf ("The target value %d was found in the binary tree\n", searchItem);
    else
        printf ("The target value was not found in the binary tree\n");
    return 0;
}