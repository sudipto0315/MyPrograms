#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    
    system("clear");
    char str[10];
    // int arr[]={};
    gets(str);
    int len=0;
    while (str[len]!='\0')
    {
        //printf("%c\n",str[len]);
        len++;
    }
    printf("%d",len-1);
    //printf("%d",len);
    // int len=strlen(str);
    // printf("%d",len);
    // for (int i = 0; i <=len; i++)
    // {
    //     printf("%d",str[i]);
    // }
    for (int i =0,j=len-1;i<=j;i++,j--){
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
    puts(str);
    
    return 0;
}
