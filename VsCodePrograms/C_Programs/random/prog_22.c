#include<stdio.h>
int main() {
for(int i=1;i<=4;i++)
{
    for(int j=4;j>=i;j--)
    {
       printf(" ");
    }
    for(int k=1;k<=i;k++)
    {
        char ch=(k+64);
        printf("%c ",ch);
    }
printf("\n");
}
return 0;
}
