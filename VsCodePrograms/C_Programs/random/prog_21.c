//program to check wheather a year is a "leap year" or "not a leap year"
//without using any if-else, break, continue, && operaor, ||operator and ?: operator.
#include<stdio.h>
int main(int argc, char const *argv[])
{
	int year,y1=0,y2=0,y3=0,andOP=0,orOP=0,m=0,l=0;
    printf("Enter a year: ");
    scanf("%d",&year);
	y1=(year%4==0);
	y2=(year%100!=0);
	andOP=y1*y2;
	y3=(year%400==0);
	orOP=(andOP+y3);
	switch (orOP)
	{
	case 1:
		while(m!=1){
			printf("leap year \n");
			m=1;
			l=1;
		}
	case 0:
		while (l!=1)
		{
			printf("not a leap year\n");
			l=1;
		}
	}
	return 0;
}
