#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char str[]="College Bullshit";
    char *ptr =str;//ptr now points to str[0]
    int i=0;
    while(*ptr!='\0'){
        printf("%c",*ptr);
        ptr++;
        i++;
    }
    return 0;
}