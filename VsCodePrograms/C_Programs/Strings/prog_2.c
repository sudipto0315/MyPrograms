#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    // int i=0;
    // char arr[]="Hello World";
    // while (i<11)//length of Hello World is 11 characters
    // {
    //     printf("%c",arr[i]);
    //     i++;
    // }

    // char arr2[]="I love Programing \0";
    // while (arr2[i]!='\0')//length of Hello World is 11 characters
    // {
    //     printf("%c",arr2[i]);
    //     i++;
    // }
    char arr[]="Sudipto";
    int i=0;
    while (arr[i]!='\0')
    {
        //printf("%c",arr[i]);
        //printf("%c",i[arr]);
        //printf("%c",*(i+arr));
        printf("%c",*(arr+i));
        i++;
    }
    
    return 0;
}
