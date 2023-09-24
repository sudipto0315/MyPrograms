#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t node;
typedef node *Node;
struct Node_t
{
    int data;
    Node prev;
    Node next;
};

Node newNode(int data)
{
    Node new = (Node)calloc(1, sizeof(node));
    new->data = data;
    return new;
}

void addLast(Node *head_add, int data)
{
    Node prev = NULL;
    if (*(head_add) == NULL)
    {
        *head_add = newNode(data);
    }

    else
    {
        Node head = *head_add;
        while (1)
        {
            prev = head;
            if (head->next == NULL)
                break;
            head = head->next;
        }
        head->next = newNode(data);
        head = head->next;
        head->prev = prev;
    }
}

void doubly_FlistReader(Node list)
{
    if (list == NULL)
    {
        printf("NULL");
        return;
    }
    while (1)
    {

        printf("%d->", list->data);
        if (list->next == NULL)
        {
            printf("NULL");
            break;
        }
        list = list->next;
    }
}

Node mergeIt(Node first, Node second)
{
    Node output = NULL;
    int flag = 0;
    while (first != NULL || second != NULL)
    {
        // doubly_FlistReader(output);
        if (flag == 1)
        {
            while (first != NULL)
            {
                addLast(&output, first->data);
                first = first->next;
            }
            return output;
        }

        if (flag == 2)
        {
            while (second != NULL)
            {
                addLast(&output, second->data);
                second = second->next;
            }
            return output;
        }

        int data_first = first->data;
        int data_second = second->data;
        // printf("data_first:%d data_second: %d\n", data_first, data_second);
        if (data_first < data_second)
        {
            addLast(&output, data_first);
            if (first->next == NULL)
            {
                flag = 2;
            }
            first = first->next;
        }

        else
        {
            addLast(&output, data_second);
            if (second->next == NULL)
            {
                flag = 1;
            }
            second = second->next;
        }
    }
    return output;
}

void main()
{
    Node head1 = NULL, tail1 = NULL;
    Node head2 = NULL, tail2 = NULL;
    int n1;
    printf("Enter the size of list 1: ");
    scanf("%d", &n1);
    printf("\n");
    for (int i = 0; i < n1; i++)
    {
        int data = 0;
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &data);
        addLast(&head1, data);
        printf("\n");
    }

    int n2;
    printf("Enter the size of list 2: ");
    scanf("%d", &n2);
    printf("\n");
    for (int i = 0; i < n2; i++)
    {
        int data = 0;
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &data);
        addLast(&head2, data);
        printf("\n");
    }

    doubly_FlistReader(head1);
    printf("\n");
    doubly_FlistReader(head2);
    printf("\n");
    Node output = mergeIt(head1, head2);
    doubly_FlistReader(output);
}
