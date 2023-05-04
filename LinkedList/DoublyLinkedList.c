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
    ;
}

void insertAtIndex(Node *pnode, int data, int index)
{
    if (index == 0)
    {
        insertAtStart(pnode, data);
        return;
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
        return;
    }

    if (node->next == NULL)
    {
        insertAtLast(pnode, data);
        return;
    }
    Node new_node = newNode(data, node->next, node);
    node->next->prev = new_node;
    node->next = new_node;
}

void removeFirst(Node *pnode)
{
    if(*pnode==NULL)
    {
        return ;
    }

    Node node =  *pnode;
    if(node->next==NULL)
    {
        *pnode=NULL;
        free(node);
        return ;
    }

    node->next->prev=NULL;
    *pnode = node->next;
    free(node);
}

void removeLast(Node *pnode)
{
    Node node = *pnode;
    if(node == NULL || node->next==NULL)
    {
        removeFirst(pnode);
        return ;
    }

    while(node->next->next)
    {
        node=node->next;
    }

    Node temp = node->next;
    node->next = NULL;
    free(temp);


}

void removeIndex(Node *pnode,int index)
{
    if(index==0)
    {
        removeFirst(pnode);
        return ;
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
        return ;
    }

    if(node->next->next==NULL)
    {
        removeLast(pnode);
        return ;
    }

    Node temp = node->next;
    temp->next->prev = node;
    node->next = temp->next;
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
    insertAtStart(&head, 1);
    insertAtStart(&head, 2);
    insertAtStart(&head, 3);
    insertAtLast(&head, 50);
    display(head);
    insertAtIndex(&head, 70, 3);
    display(head);
    removeIndex(&head,2);
    display(head);
    return 0;
}