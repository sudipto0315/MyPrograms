#include<stdio.h>
int main(){
int n=5;
int c=15;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<i;j++)
    {
        printf(" ");
    }
    for(int k=n;k>=i;k--)
    {
        if( k%2!=0)
        {
        char ch=c+64;
        printf("%c ",ch);
        }
        else if( k%2==0)
        {
            char ch1=c+96;
            printf("%c ",ch1);
        }
        c--;
    }
    printf("\n");
}
return 0;
}