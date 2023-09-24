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

int removeFirst(Node *pnode) {
    if (*pnode == NULL)
        return -1;
    Node node = *pnode;
    *pnode = (*pnode)->next;
    int data = node->data;
    free(node);
    return data;
}

int removeFrom(Node *pnode, unsigned int index) {
    if (*pnode == NULL || index == 0)
        return removeFirst(pnode);
    Node node = *pnode;
    index--;
    while (node && index) {
        node = node->next;
        index --;
    }
    if (node == NULL || node->next == NULL)
        return -1;
    Node tempNode = node->next;
    node->next = tempNode->next;
    int data = tempNode->data;
    free(tempNode);
    return data;
}

int printList(Node node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
    return 0 ;
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

    //inserting at the beginning
    printf("Enter the element you want to insert at the beginning : ");
    scanf("%d",&inputElement);
    addFirst(&list,inputElement);
    printf("The Linked List after Insertion at the Beginning is : "); printList(list);
    
    //Deleting the middle element
    printf("\nNow deleting the middle Node :\n\n");
    int index = list_Len/2;
    data = removeFrom(&list, index);
    printf("Removed Node %d from index %d\n", data, index);
    printf("The Linked List after Deleting the Middle Node is : "); printList(list);

    return 0;
}

