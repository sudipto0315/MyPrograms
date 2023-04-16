#include<stdio.h>
int main() {
int c=0,s=0;
for(int i=1;i<=5;i++)
{
    for(int j=5;j>=i;j--)
    {
       printf(" ");
    }
    for(int k=1;k<=i;k++)
    {
        ++c;
        if (i==3 || i==4){
            if (c%2==0)
            {
                s=64+c;
            }
            else
            {
                s=64+32+c;
            }
            char ch=(char)s;
            printf("%c ",ch);
            }
        else {
            if (c%2==0)
        {
            s=64+32+c;
        }
        else
        {
            s=64+c;
        }
        char ch=(char)s;
        printf("%c ",ch);
        }
    }
printf("\n");
}
return 0;
}