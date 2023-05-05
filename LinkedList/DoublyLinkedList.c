#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;

struct Node_t
{
    int data;
    Node next;
    Node prev;
};

Node newNode(int data, Node next, Node prev)
{
    Node node = (Node)malloc(sizeof(Node_t));
    node->data = data;
    node->next = next;
    node->prev = prev;

    return node;
}

void insertAtStart(Node *pnode, int data)
{
    Node new_node = newNode(data, *pnode, NULL);
    if (*pnode != NULL)
    {
        (*pnode)->prev = new_node;
    }
    *pnode = new_node;
}

void insertAtLast(Node *pnode, int data)
{
    if (*pnode == NULL)
    {
        insertAtStart(pnode, data);
    }

    Node node = *pnode;
    while (node->next)
    {
        node = node->next;
    }

    node->next = newNode(data, NULL, node);
}

int insertAtIndex(Node *pnode, int data, int index)
{
    if (index == 0)
    {
        insertAtStart(pnode, data);
        return -1;
    }
    Node node = *pnode;
    index--;
    while (index > 0 && node != NULL)
    {
        node = node->next;
        index--;
    }
    if (node == NULL)
    {
        return -1;
    }

    if (node->next == NULL)
    {
        insertAtLast(pnode, data);
        return -1;
    }
    Node new_node = newNode(data, node->next, node);
    node->next->prev = new_node;
    node->next = new_node;
}

int removeFirst(Node *pnode)
{
    if(*pnode==NULL)
    {
        return -1;
    }

    Node node =  *pnode;
    if(node->next==NULL)
    {
        *pnode=NULL;
        free(node);
        return -1;
    }

    node->next->prev=NULL;
    *pnode = node->next;
    return(node->data);
    free(node);
}

int removeLast(Node *pnode)
{
    Node node = *pnode;
    if(node == NULL || node->next==NULL)
    {
        removeFirst(pnode);
        return -1;
    }

    while(node->next->next)
    {
        node=node->next;
    }

    Node temp = node->next;
    node->next = NULL;
    return(temp->data);
    free(temp);
}

int removeIndex(Node *pnode,int index)
{
    if(index==0)
    {
        removeFirst(pnode);
        return -1;
    }

    Node node = *pnode;
    index--;

    while(node && index)
    {
        node = node->next;
        index--;
    }

    if(node==NULL || node->next==NULL)
    {
        return -1;
    }

    if(node->next->next==NULL)
    {
        removeLast(pnode);
        return -1;
    }

    Node temp = node->next;
    temp->next->prev = node;
    node->next = temp->next;
    return(temp->data);
    free(temp);
}

void display(Node node)
{
    Node end;
    printf("\nIn Forward Direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        end = node;
        node = node->next;
    }

    printf("\nIn Backward Direction \n");
    while (end != NULL)
    {
        printf(" %d ", end->data);
        end = end->prev;
    }
    printf("\n");
}

int main()
{
    Node head = NULL;
    int data,index,deletedElement;
    int n=0 , list_Len=0;;
    // insertAtStart(&head, 1);
    // insertAtStart(&head, 2);
    // insertAtStart(&head, 3);
    // insertAtLast(&head, 50);
    // display(head);
    // insertAtIndex(&head, 70, 3);
    // display(head);
    // removeIndex(&head,2);
    // display(head);
    printf("\t*** Welcome to Doubly Linked List Menu Based Program *** \n");
    printf("Enter the length of the Doubly linked list: ");
    scanf("%d",&list_Len);
    printf("Enter the elements:\n");
    for (int i = 1; i <= list_Len; i++)
    {   
        printf("Enter element %d : ",i);
        scanf("%d", &data);
        insertAtStart(&head, data);
    }
    printf("\n");
    printf("\t*** Following Are The Operations You Can Perform On The Linked List *** \n"
        "Press 1: To add Number in the begining of the list.\n"
        "Press 2: To add Number at the nth position of the list.\n"
        "Press 3: To add Number at the last of the list.\n"
        "Press 4: To remove Number in the begining of the list.\n"
        "Press 5: To remove Number at the nth position of the list.\n"
        "Press 6: To remove Number at the last of the list.\n"
        "Press 8: To print the list.\n"
        "Press 0: To exit from the Program.\n\n");
while(1){
    printf("Please Enter Your Choice:");
    scanf("%d",&n);
    if (n==0){
        printf("\tThank You\n");
        printf("\tHave a nice day\n");
        exit(0);
        }
    else if (n==1)
    {
    printf("Please Enter the Number which you want to add in the begining:");
    scanf("%d",&data);
     insertAtStart(&head,data);     
    }
    else if (n==2)
    {
    printf("Please Enter the position at which you want to add a number:");
    scanf("%d",&index);
    printf("Please Enter the Number which you want to add at the %d position of the list:",index);
    scanf("%d",&data);
     insertAtIndex(&head,data,index);     
    }
    else if (n==3)
    {
    printf("Please Enter the Number which you want to add at the last:");
    scanf("%d",&data);
     insertAtLast(&head,data);     
    }
    else if (n==4)
    {
     deletedElement=removeFirst(&head);     
    printf("The removed value is: %d\n",deletedElement);
    }
    else if (n==5)
    {
     deletedElement=removeLast(&head);     
    printf("The removed value is: %d\n",deletedElement);
    }
    else if (n==6)
    {
    printf("Please Enter the position at which you want to remove a number:");
    scanf("%d",&index);
     deletedElement=removeIndex(&head,index);     
    printf("The removed value is: %d\n",deletedElement);
    }
    else if (n==8)
    {
        display(head);
    }
    else
    {
        printf("You Have Entered a Wrong choice!!!\n"
                "Please Try Again.");
    }
    getchar();
    }
    return 0;
}