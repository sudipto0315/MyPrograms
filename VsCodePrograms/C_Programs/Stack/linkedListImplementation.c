#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
    printf("Element %d pushed onto the stack.\n", element);
}

int pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow. Cannot pop element.\n");
        return -1;
    }
    else
    {
        Node *temp = top;
        int element = temp->data;
        top = top->next;
        free(temp);
        printf("Element %d popped from the stack.\n", element);
        return element;
    }
}

void display()
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        Node *current = top;
        printf("Current stack: ");
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, element;

    while (1)
    {
        printf("Stack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            element = pop();
            if (element != -1)
            {
                printf("Popped element: %d\n", element);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}
