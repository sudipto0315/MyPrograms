/*
Write a menu-based (use do-while loop and switch-case construct to create the menu) program in C to perform the following operations on strings:
i. Concatenate two strings without using the strcat function. The strings are user inputs.
ii. Concatenate two strings using the strcat function. The strings are user inputs.
iii. Compare two strings without using the strcmp function. The strings are user inputs.
iv. Compare two strings using the strcmp function. The strings are user inputs.
v. Calculate the length of a string without using the strlen function. The string is user input.
vi. Calculate the length of a string using the strlen function. The string is user input.
vii. Copy one string to another string without using the strcpy function. The string is user input.
viii. Copy one string to another string using the strcpy function. The string is user input.
ix. A menu "exit" to terminate the program.
*/
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
void mystrcat1(char a[], char b[]) {
    int i = 0, j = 0;
    while (a[i])
        i++;
    while (b[j])
        a[i++] = b[j++];
    a[i] = '\0';
}
void mystrcat2(char *a, char *b) {
    while (*a++)
        ;
    a--;
    while (*b)
        *a++ = *b++;
    *a = '\0';
}
int mystrcmp(char a[], char b[]) {
    for (int i = 0; a[i] && b[i]; i++)
        if (a[i] != b[i])
            return a[i] - b[i];
    return 0;
}
int mystrlen(char a[]) {
    int i = 0;
    while (a[i])
        i++;
    return i;
}
void mystrcpy(char *a, char *b) {
    while (*b)
        *a++ = *b++;
}
int main() {
    do {
        int n = 0;
        printf(
            "1 - Concatenate two strings without using strcat.\n"
            "2 - Concatenate two strings using strcat.\n"
            "3 - Compare two strings without using strcmp.\n"
            "4 - Compare two strings using strcmp.\n"
            "5 - Calculate length of a string without using strlen.\n"
            "6 - Calculate length of a string using strlen.\n"
            "7 - Copy one string to another string without using strcpy.    \n"
            "8 - Copy one string to another string using strcpy.\n"
            "9 - Exit.\n"
            "Enter your Choice: "
        );
        scanf("%d", &n);
        char a[MAX_SIZE] = "", b[MAX_SIZE] = "";
        switch (n) {
            case 1: printf("Enter the first string: ");
                fflush(stdin);
                gets(a);
                fflush(stdin);
                printf("Enter the second string: ");
                gets(b);
                printf("After concatenation: ");
                //mystrcat1(a, b); // an alternative
                mystrcat2(a, b);
                puts(a);
                break;
            case 2: printf("Enter the first string: ");
                fflush(stdin);
                gets(a);
                fflush(stdin);
                printf("Enter the second string: ");
                gets(b);
                printf("After concatenation: ");
                strcat(a, b);
                puts(a);
                break;
            case 3: printf("Enter the first string: ");
                fflush(stdin);
                gets(a);
                fflush(stdin);
                printf("Enter the second string: ");
                gets(b);
                puts(mystrcmp(a, b) ? "Different." : "Same.");
                break;
            case 4: printf("Enter the first string: ");
                fflush(stdin);
                gets(a);
                fflush(stdin);
                printf("Enter the second string: ");
                gets(b);
                puts(strcmp(a, b) ? "Different." : "Same.");
                break;
            case 5: printf("Enter the string: ");
                fflush(stdin);
                gets(a);
                printf("Length: %d\n", mystrlen(a));
                break;
            case 6: printf("Enter the string: ");
                fflush(stdin);
                gets(a);
                printf("Length: %d\n", strlen(a));
                break;
            case 7: printf("Enter the string: ");
                fflush(stdin);
                gets(a);
                mystrcpy(b, a);
                puts(b);
                break;
            case 8: printf("Enter the string: ");
                fflush(stdin);
                gets(a);
                strcpy(b, a);
                puts(b);
                break;
            case 9: return 0;
        }
    } while (1);
    return 0;
}
