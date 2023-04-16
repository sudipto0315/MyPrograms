#include<stdio.h>
int main(int argc, char const *argv[])
{
    //1
    char a[]={'a','t','l','a','s'};
    for (int i = 0; i < 5; i++)
    {
        printf("%c",a[i]);
    }
    printf("\n");
    //2
    char ch='a';
    printf("%c\n",ch);
    //char ch='ab';
    //printf("%c\n",ch) -->> Not Allowed

    //3
    char ch1='\0';
    int x=0;
    char s = (char)x; //a -> '\0'
    printf("%c",s);
    return 0;
}
