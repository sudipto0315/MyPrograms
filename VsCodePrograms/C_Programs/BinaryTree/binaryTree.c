#include <stdio.h>
#include <stdlib.h>

struct node
{
  int item;
  struct node *left;
  struct node *right;
};

// Inorder traversal
void inorderTraversal(struct node *root)
{
  if (root == NULL)
    return;
  inorderTraversal(root->left);
  printf("%d ", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node *root)
{
  if (root == NULL)
    return;
  printf("%d ", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node *root)
{
  if (root == NULL)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ", root->item);
}

// level order trav starts //
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
      printf("%d ", temp->item);
      if (temp->left)
        enqueue(temp->left);

      if (temp->right)
        enqueue(temp->right);
    }
  }
}

// level order trav ends//

// Create a new Node
struct node *create(int value)
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
  root->left = create(value);
  return root->left;
}

// Insert on the right of the node
struct node *insertRight(struct node *root, int value)
{
  root->right = create(value);
  return root->right;
}

// Build the binary tree
struct node *buildTree()
{
  int value=0;
  struct node *root = NULL;

  printf("Enter node value (enter 0 to stop): ");
  scanf("%d", &value);

  if (value != 0)
  {
    root = create(value);

    printf("Enter left child of %d\n", value);
    root->left = buildTree();

    printf("Enter right child of %d\n", value);
    root->right = buildTree();
  }

  return root;
}

int main()
{
  struct node *root = NULL;

  printf("Build the binary tree\n");
  root = buildTree();

  printf("\nTraversal of the inserted binary tree \n");
  printf("Inorder traversal: ");
  inorderTraversal(root);

  printf("\nPreorder traversal: ");
  preorderTraversal(root);

  printf("\nPostorder traversal: ");
  postorderTraversal(root);

  printf("\nLevel Order traversal:\n");
  levelOrderTrav(root);
  return 0;
}