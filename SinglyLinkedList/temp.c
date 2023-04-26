#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
    char str[100];
    printf("Please enter the string \n");
    scanf("%d[^\n]s",str);
    fflush(stdin);
    char sub[100];
    printf("please enter the substring \n");
    scanf("%d[^\n]s",sub);
    int l = strlen(sub);
    int k,j;
    for (int i = 0; str[i+l-1]; i++)
    {
        k=i;
        for (int j = 0; j <= l-1; j++)
        {
            if (str[k]!=sub[j])
            {
                break;
            }
            k++; 
        }
        if (j==l)
        {
            printf("the substring is present in the string at index %d \n",i);
            return 0;
        }
    }
    printf("the substring is not present in the string \n"); 
    return 0;
}
