#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct Node_t
{
    int data;
    struct Node_t *left;
    struct Node_t *right;
};
typedef struct Node_t *Node;
typedef struct Node_t node;

Node queue[500];
int front = -1;
int rear = -1;

void enqueue(Node data)
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

Node dequeue()
{
    Node data = queue[front];
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

Node newNode(int data)
{
    Node newnode = (Node)malloc(sizeof(node));
    newnode->data=data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node treeCreator(Node root)
{
    int data;

    printf("enter data:");
    scanf("%d", &data);

    if (data == -1)
        return NULL;
    root = newNode(data);

    printf("\nenter the data for left of %d", data);
    root->left = treeCreator(root->left);

    printf("\nenter the data for right of %d", data);
    root->right = treeCreator(root->right);

    return root;
}

// Node treeCreator(Node root){
// printf("\nenter data\n");
// int data;
// scanf("%d",&data);
// if(data!=-1)
// root=newNode(data);
// else return NULL;

// printf("enter data for left of %d",data);

// root->left=treeCreator(root->left);

// printf("enter data for right of %d",data);

// root->right=treeCreator(root->right);

// return root;
// }

void levelOrderTrav(Node root)
{
    enqueue(root);
    enqueue(NULL);
    while (!isEmpty())
    {
        Node temp = dequeue();
        if (temp == NULL)
        {
            printf("\n");
            if (!isEmpty())
                enqueue(NULL);
        }
        else
        {
            printf("%d ", temp->data);
            if (temp->left)
                enqueue(temp->left);

            if (temp->right)
                enqueue(temp->right);
        }
    }
}


Node TreeBuilder(char* inorder,char* postorder,int size){
int i=0;
int temp;
while((postorder[i])!='\0') 
{   i++;}

if(postorder[i]=='\0')i--;
if(postorder[i]=='\0') return NULL;
else{temp=postorder[i]-'0';
//printf("%d\n",temp);
postorder[i]='\0';

//printf("inorder: %s",inorder);
//puts(inorder);
//printf("\n postorder: %s\n",postorder);
int j=0;
while(inorder[j]!=(temp+'0')){
    j++;
}
inorder[j]='\0';

Node root=newNode(temp);

root->right=TreeBuilder(inorder+j+1,postorder,size);
root->left=TreeBuilder(inorder,postorder,size);
return root;}

}

Node TreeFormer(char* postorder,char* inorder){
int i=0;
while(postorder[i+1]!='\0'){
i++;
}
//puts(postorder);
//printf("\n");
//puts(inorder);
char temp=postorder[i];
postorder[i]='\0';

if(strlen(inorder)==1){

    return newNode(temp-'0');
}

int j=0;
while(inorder[j]!=temp){
    j++;
}
inorder[j]='\0';
Node root=newNode(temp-'0');
root->right=TreeFormer(postorder,inorder+j+1);
root->left=TreeFormer(postorder,inorder);
return root;
}

void main()
{
    char inorder[100];
    printf("enter the inorder traversal:");
    fgets(inorder,60,stdin);
    fflush(stdin);
    char postorder[100];
    printf("\nenter the postorder traversal:");
    fgets(postorder,60,stdin);
    printf("\nThis is the level order traversal of the required tree:\n");
    Node root = TreeFormer(postorder,inorder);
    levelOrderTrav(root);

}
