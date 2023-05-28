// Write a program in C to print the address of each character in a given string. The string is user input.
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char a[100];
    gets(a);
    for (int i = 0; i < strlen(a); i++)
    {
        printf("the address if %c is %d \n",a[i],&a[i]);
    }
    return 0;
}
