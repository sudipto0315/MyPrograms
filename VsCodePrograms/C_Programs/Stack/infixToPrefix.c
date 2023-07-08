#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(char element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack Underflow. Cannot pop element.\n");
        return '\0';
    } else {
        Node* temp = top;
        char element = temp->data;
        top = top->next;
        free(temp);
        return element;
    }
}

int precedence(char operator) {
    switch (operator) {
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

int isOperator(char character) {
    return (character == '+' || character == '-' || character == '*' || character == '/' || character == '^');
}

void reverseString(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    reverseString(infix);

    int i = 0, j = 0;
    char character;

    while (infix[i] != '\0') {
        character = infix[i];

        if (isalnum(character)) {
            prefix[j++] = character;
        } else if (character == ')') {
            push(character);
        } else if (character == '(') {
            while (top != NULL && top->data != ')') {
                prefix[j++] = pop();
            }
            if (top == NULL) {
                printf("Invalid infix expression. Mismatched parentheses.\n");
                return;
            }
            pop();  // Remove ')' from stack
        } else if (isOperator(character)) {
            while (top != NULL && precedence(character) < precedence(top->data)) {
                prefix[j++] = pop();
            }
            push(character);
        } else {
            printf("Invalid infix expression. Unsupported character: %c\n", character);
            return;
        }

        i++;
    }

    while (top != NULL) {
        if (top->data == ')') {
            printf("Invalid infix expression. Mismatched parentheses.\n");
            return;
        }
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverseString(prefix);
}

int main() {
    char infix[100];
    char prefix[100];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
