#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int element)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack Overflow. Cannot push element.\n");
    }
    else
    {
        stack[++top] = element;
        printf("Element %d pushed onto the stack.\n", element);
    }
}

int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow. Cannot pop element.\n");
        return -1;
    }
    else
    {
        int element = stack[top--];
        printf("Element %d popped from the stack.\n", element);
        return element;
    }
}

void display()
{
    if (top < 0)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Current stack: ");
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
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
