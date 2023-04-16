#include<stdio.h>
#include<math.h>
int flag(int n,int c)
{
    int n1=n;
    while(n1!=0)
    {
        c++;
        n1=n1/10;
    }
    return c;
}
int primecheck(int n)
{
    int i=0;
    int j=0;
    for(i=1;i<=n;i++)
    {
        if(n%i==0)
            j++;
    }
    if(j==2)
        return 1;
    else
        return 0;
}
void rotate(int n)
{
    int i=1;
    int s=0;
    int d=0;
    int c2=0;
    int c1=flag(n,0);
    printf("Digits= %d\n",c1);

      while(c2<c1)
      {
          s=n%10;
          n=n/10;
          n=n+s*pow(10,(c1-1));
          printf("Rotated number %d\n",n);
          if(primecheck(n))
            printf("%d\n",n);
            c2++;
      }

}
void main()
{
    int n=113;
    rotate(n);
}