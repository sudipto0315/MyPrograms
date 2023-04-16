#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    system("clear");
    char str[10];
    puts("Enter a string");
    gets(str);
    puts("The size of string is: ");// automatically adds \n to the end of the string
    //size
    int size=0;
    for (int i = 0; str[i] != '\0'; i++)
        size++;
    printf("%d\n",size);
    //reversing
    for (int i=size;i>=0;i--){
        printf("%c",str[i]);
    }
    //puts(str);
    return 0;
}