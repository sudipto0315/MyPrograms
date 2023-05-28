#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void addFirst(struct node **head, int data)
{
    struct node *newNode = malloc(sizeof(struct node));

    if (head == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        newNode->data = data;
        newNode->next = *head;
        *head = newNode;
    }
}
struct node *intersect(struct node *head_1, struct node *head_2)
{
    // if (head_1 == NULL && head_2 == NULL)
    // {
    //     return NULL;
    // }
    struct node *A = head_1;
    struct node *B = head_2;

    while (A != B)
    {
        if (A != NULL)
        {
            A = A->next;
        }
        else
        {
            A = head_2;
        }
        if (B != NULL)
        {
            B = B->next;
        }
        else
        {
            B = head_1;
        }
    }
    return A;
}
void printLL(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    struct node *head_1 = NULL;
    struct node *head_2 = NULL;
    addFirst(&head_1, 3);
    addFirst(&head_1, 4);
    addFirst(&head_1, 5);
    addFirst(&head_1, 6);
    addFirst(&head_1, 7);
    printLL(head_1);
    addFirst(&head_2, 2);
    addFirst(&head_2, 24);
    addFirst(&head_2, 23);
    addFirst(&head_2, 26);
    addFirst(&head_2, 26);
    printLL(head_2);

    head_2->next->next->next = head_1->next->next;
    printLL(head_2);

    printf("%d\n", (intersect(head_1, head_2))->data);
}
