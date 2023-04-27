#include<stdio.h>
#include<stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;
typedef Node head;

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

int printList(Node node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
    return 0 ;
}

int size (Node head)
{
  int counter=0;

  // as linked list will end when Node is Null
  while (head != NULL)
    {
      head = head->next;
      counter++;
    }
 return counter;
}

int checkPalindrome (Node head, int counter)

{
    int i = 0, j;
    Node front, rear;
    while (i != counter / 2)
    {
        front = rear = head;
        for (j = 0; j < i; j++)
        {
            front = front->next;
        }
        for (j = 0; j < counter - (i + 1); j++)
        {
            rear = rear->next;
        }
        if (front->data != rear->data)
        {
            return 0;
        }
        else
        {
            i++;
        }
    }

    return 1;
}

int reverseLinkedList(Node *head){
    Node prev = NULL;
    Node current = *head;
    Node next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(int argc, char const *argv[])
{
    Node head = NULL;
    int counter,result;
    input_elements(&head);
    printf("\nThe original Linked List is : "); printList(head);

    //Now checking weather a Linked List is Palindrome

    counter = size(head);
    result = checkPalindrome(head,counter);
    if (result == 1)
    {
        printf("\nTh Llinked List is a Palindrome.\n");
    }
    else
    {
        printf("\nThe Linked List is NOT a Palindrome.\n");
    }

    // reversing the Linked List

    printf("\nNow reversing the Linked List:\n");
    reverseLinkedList(&head);
    printf("The Reversed Linked List is : "); printList(head);
    return 0;
}
