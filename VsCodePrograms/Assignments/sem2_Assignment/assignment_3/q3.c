#include<stdio.h>
#include<stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;

struct Node_t
{
    int data;
    Node next;
};

Node newNode(int data, Node next) {
    Node node = (Node) calloc(1, sizeof (Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void insertFirst(Node *head, int data) {
    *head = newNode(data, *head);
}

int input_elements(Node *head){
    int list_Len = 0,data=0;
    printf("Enter the length of the Linked List: ");
    scanf("%d",&list_Len);
    printf("\n");
    for (int i = 1; i <= list_Len; i++)
    {
        printf("Enter the %d element: ",i);
        scanf("%d",&data);
        insertFirst(head, data);
    }
    
}

int search(Node pnode, int data){
    while (pnode != NULL){
        if (pnode->data == data)
        {
            return 1;
        }
        pnode = pnode->next;
    }
}

void insert(Node *pnode,int data){
    Node newNode = (Node)malloc(sizeof(Node_t));
    newNode->data = data;
    newNode->next= *pnode;
    *pnode = newNode;
}

struct Node_t **findintersect(Node phead, Node qhead, Node *intersectLL)
{
    while (phead != NULL)
    {
        if(search(qhead, phead->data)){
            insert(intersectLL, phead->data);
        }
    phead = phead->next;
    }
    return intersectLL;
}

int printList(Node node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
    return 0 ;
}

int main(int argc, char const *argv[])
{
    Node phead, qhead, intersectLL;
    phead = qhead = intersectLL = NULL;
    printf("Enter elements in the list 1\n");
    input_elements(&phead);
    printf("Enter elements in the list 2\n");
    input_elements(&qhead);
    findintersect(phead, qhead, &intersectLL);
    printf("\nDisplaying list 1:\n");
    printList(phead);
    printf("Displaying list 2:\n");
    printList(qhead);
    printf("Displaying the intersection of the 2 lists:\n");
    if (intersectLL == NULL)
    {
        printf("Null\n");
    }
    else
    {
        printList(intersectLL);
    }
    return 0;
}
