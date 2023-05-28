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

void addNum(Node first, Node second, Node* list3)
{
    int sum = 0;
    int newVal1 =0;
    int newVal2 =0;
    while (first != NULL || second != NULL)
    {
        if (first)
            newVal1 = first->data;
        if (second)
            newVal2 = second->data;
        sum = newVal1+newVal2;
        addFirst(list3,sum);
        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }
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
    Node list1 = NULL;
    Node list2 = NULL;
    Node list3 = NULL;
    //user input for the 1st linked list
    int list_Len1=0,list_Len2; 
    printf("Enter the length of the 1st linked list: ");
    scanf("%d",&list_Len1);
    int inputElement =0;
    printf("Enter the elements:\n");
    for (int i = 1; i <= list_Len1; i++)
    {   
        printf("Enter element %d :",i);
        scanf("%d", &inputElement);
        addFirst(&list1, inputElement);
    }
    //user input for the 2nd linked list

    printf("Enter the length of the 2st linked list: ");
    scanf("%d",&list_Len2);
    printf("Enter the elements:\n");
    for (int i = 1; i <= list_Len2; i++)
    {   
        printf("Enter element %d :",i);
        scanf("%d", &inputElement);
        addFirst(&list2, inputElement);
    }

    printf("The 1st Linked List is : "); printList(list1);
    printf("The 2nd Linked List is : "); printList(list2);

    addNum(list1, list2, &list3);
    printf("The Added Linked List is : "); printList(list3);

    return 0;
}