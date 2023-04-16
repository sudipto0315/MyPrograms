#include<stdio.h>
#include<math.h>
int main(){
    int n=5; int r=0; int c=0; int s=0;
    while (n!=0)
    {
        r=n%2;
        n=n/2;
        s=s+r*pow(10,c);
        ++c;
    }
    printf("%d",s);
    return 0;
}
