#include <stdio.h>
#include <stdlib.h>
int z,n;
int inorderArray[];
struct node {
	int key;
	struct node *left, *right;
};

struct node* queue[500];
int front = -1;
int rear = -1;


void enqueue(struct node* data)
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

struct node* dequeue()
{
    struct node* data = queue[front];
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

struct node* newNode(int item)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

int inorder(struct node* root,int inorderArray[])
{
	if (root != NULL) {
		inorder(root->left,inorderArray);
		printf("%d ", root->key);
        inorderArray[z++]=root->key;
		inorder(root->right,inorderArray);
	}
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	return node;
}

void levelOrderTrav(struct node* root)
{
    enqueue(root);
    enqueue(NULL);
    while (!isEmpty())
    {
        struct node* temp = dequeue();
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
    struct node* root = NULL;
    int  item;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    inorderArray[n];

    printf("Enter %d elements to insert:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        root = insert(root, item);
    }

    printf("Inorder traversal: ");
    inorder(root,inorderArray);
	printf("\n");
    int k = 0;
    scanf("%d",&k);
    printf("The %d th largest element will be: ",k);
    printf("%d",inorderArray[n-k]);
	printf("\n");
	//levelOrderTrav(root);
    return 0;
}