#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(char element)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack Underflow. Cannot pop element.\n");
        return '\0';
    }
    else
    {
        Node *temp = top;
        char element = temp->data;
        top = top->next;
        free(temp);
        return element;
    }
}

int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int isOperator(char character)
{
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}

void infixToPostfix(char *infix, char *postfix)
{
    int i = 0, j = 0;
    char character;

    while (infix[i] != '\0')
    {
        character = infix[i];

        if (isalnum(character))
        {
            postfix[j++] = character;
        }
        else if (character == '(')
        {
            push(character);
        }
        else if (character == ')')
        {
            while (top != NULL && top->data != '(')
            {
                postfix[j++] = pop();
            }
            if (top == NULL)
            {
                printf("Invalid infix expression. Mismatched parentheses.\n");
                return;
            }
            pop(); // Remove '(' from stack
        }
        else if (isOperator(character))
        {
            while (top != NULL && precedence(character) <= precedence(top->data))
            {
                postfix[j++] = pop();
            }
            push(character);
        }
        else
        {
            printf("Invalid infix expression. Unsupported character: %c\n", character);
            return;
        }

        i++;
    }

    while (top != NULL)
    {
        if (top->data == '(')
        {
            printf("Invalid infix expression. Mismatched parentheses.\n");
            return;
        }
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100];
    char postfix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
