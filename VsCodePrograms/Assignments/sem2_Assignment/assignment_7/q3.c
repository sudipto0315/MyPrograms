#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;
typedef Node List;

struct Node_t
{
    int data;
    Node next;
};

Node newNode(int data, Node next)
{
    Node node = (Node)calloc(1, sizeof(Node_t));
    node->data = data;
    node->next = next;
    return node;
}

void addFirst(Node *pnode, int data)
{
    *pnode = newNode(data, *pnode);
}

void addLast(Node *pnode, int data)
{
    if (*pnode == NULL)
    {
        addFirst(pnode, data);
        return;
    }
    Node node = *pnode;
    while (node->next)
        node = node->next;
    node->next = newNode(data, NULL);
}

int printList(Node node)
{
    while (node)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
    return 0;
}

// Function to find the middle node of the linked list
Node findMiddle(Node head)
{
    if (head == NULL)
        return head;

    Node slow = head;
    Node fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// Function to merge two sorted lists
Node mergeSorted(Node left, Node right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node res = NULL;

    if (left->data <= right->data)
    {
        res = left;
        res->next = mergeSorted(left->next, right);
    }
    else
    {
        res = right;
        res->next = mergeSorted(left, right->next);
    }

    return res;
}

// Function to sort the list
Node mergeSort(Node head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node mid = findMiddle(head);
    Node nextToMid = mid->next;
    mid->next = NULL;

    Node left = mergeSort(head);
    Node right = mergeSort(nextToMid);

    Node res = mergeSorted(left, right);

    return res;
}

int main()
{
    int data = 0;
    Node list = NULL;
    // user input for the linked list
    int list_Len = 0;
    printf("Enter the length of the linked list: ");
    scanf("%d", &list_Len);
    int inputElement = 0;
    printf("Enter the elements:\n");
    for (int i = 1; i <= list_Len; i++)
    {
        printf("Enter element %d : ", i);
        scanf("%d", &inputElement);
        addLast(&list, inputElement);
    }
    printf("The original Linked List is : ");
    printList(list);
    list = mergeSort(list);

    // printing the list after sorting
    printf("List after sorting -\n");
    printList(list);

    return 0;
}