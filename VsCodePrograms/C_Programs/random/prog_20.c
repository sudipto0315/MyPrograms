#include<stdio.h>
void main()
{
    int year;
    printf("Enter a year: ");
    scanf("%d",&year);
    int i,j,k,l;
    i=year%4;
    j=year%100;
    k=year%400;
    l=1;
    int m=1;
    int n=1;
    switch(i)
    {   
        case 0:
        {
            switch(j)
            {
                case 0:
                {
                    switch(k)
                    {
                        case 0:
                        printf("Leap year");
                        l=0;
                        m=0;
                        n=0;
                    }
                    while(m){
                    printf("Not a leap year");
                    l=0;
                    n=0;
                    m=0;}
                }
            }
    while(n){
    printf("Leap year");
    l=0;
    n=0;}
    }
    }
    while(l)
    {
    printf("Not a leap year");
    l=0;
    }
    }