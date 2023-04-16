#include <stdio.h>
int main(){
for(int i=4;i>=1;i--)
{
    for (int k=4; k>=i;k--)
    {
        printf(" ");
    }
    for(int j=1;j<=i;j++)
    {
        char ch=(j+64);
        printf("%c ",ch); 
    }
    printf("\n");
}
return 0;
}
