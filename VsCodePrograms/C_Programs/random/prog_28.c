#include<stdio.h>
int rec(int x){
    int f;
    if (x==1){
        return(1);
    }
    else
        f=x*rec(x-1);
        return(f);
}
int main(int argc, char const *argv[])
{
    int a, fact;
    scanf("%d",&a);
    fact=rec(a);
    printf("%d",fact);
    return 0;
}
