// #include<stdio.h>
// #include<math.h>
// int isPrime(int n)
// {
//     int flag = 0;
//     for(int i =1;i<=n;i++)
//     {
//         if(n%i==0)
//         flag++;
//     }
//     if(flag==2)
//     return 1;
//     else
//     return 0;
// }
// int digits(int n,int sum)
// {
//     return n==0?sum:digits(n/10,sum+1);
// }
// int main()
// {
//     int a = 113;
//     int d=digits(a,0);
//     for(int i =1;i<=d;i++)
//     {
//         int n = a;
//         double temp = (n%10)*pow(10,d-1)+n/10;
//         a=temp;
//         if(isPrime(temp))
//         printf("%lg\n",temp);
//     }
//     // printf("%d",d);
//     return 0;
// }
#include<stdio.h>
#include<math.h>
int flag(int n)
{
    int c=0;
    while(n>0)
    {
        c=c+1;
        n=n/10;
    }
    return c;

}
int primecheck(int n)
{
    int b=0;
    for(int i=1;i<=n;i++)
    {

        if(n%i==0)
        {
            b=b+1;
        }

    }
    if(b==2)
    {
        int z=1;
        return z ;
    }
    else{
        int z=0;
        return z;
    }
}
int main()
{

    int num=700;
    int x=flag(num);
    printf("no of digits=%d\n",x);
    int s=0;
    for(int i=0;i<x;i++)
    {
        int c=0;
        int y=num%10;
        num=(y*pow(10,x-1))+(num/10);
        printf("%d\n",num);
        c=primecheck(num);
        printf("%d\n",c);
        if(c==1)
        {
            s=s+1;
        }
        else{
            s=s+0;
        }


    }
    printf("%d\n",s);
    if(s==x)
    {
        printf("All are prime");
    }

}