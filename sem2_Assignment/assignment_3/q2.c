#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;
typedef Node List;

struct Node_t {
    int data;
    Node next;
};

Node newNode(int data, Node next) {
    Node node = (Node) calloc(1, sizeof (Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void addFirst(Node *pnode, int data) {
    *pnode = newNode(data, *pnode);
}

void printList(Node node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main()
{
    int data=0;
    Node list = NULL;
    //user input for the linked list
    int list_Len=0; 
    printf("Enter the length of the linked list: ");
    scanf("%d",&list_Len);
    int inputElement =0;
    printf("Enter the elements:\n");
    for (int i = 1; i <= list_Len; i++)
    {   
        printf("Enter element %d : ",i);
        scanf("%d", &inputElement);
        addFirst(&list, inputElement);
    }
    printf("The original Linked List is : "); printList(list);
    
    return 0;
}