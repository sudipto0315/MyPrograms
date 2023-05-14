#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 100
char stack[N];
int top = -1;
void Push(char x)
{
    stack[++top] = x;
}
char Pop()
{
    char a = stack[top--];
    return a;
}

bool isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}

void ReverseString(char st[])
{
    int n = strlen(st);
    printf("\nReversed string: ");
    for (int i = 0; i < n; i++)
    {
        Push(st[i]);
    }
    while (!isEmpty())
    {
        char a = Pop();
        printf("%c", a);
    }
}

int main()
{
    char st[100];
    printf("Enter a string: ");
    // fgets(st, 100, stdin);
    gets(st);
    ReverseString(st);

    return 0;
}
