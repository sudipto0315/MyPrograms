//Series: 1/0! + 1/4! + 1/8! + 1/16! + ... 1/N!
#include<stdio.h>
    
unsigned long factorial(int num)
{
	int i;
	unsigned long fact=1;
	
	for(i=num; i>=1; i--)
        fact= fact*i;
	
	return fact;
}

int main()
{
	int i,N;
	float sum;
	
	printf("Enter the value of N: ");
	scanf("%d",&N);
	
	sum=0.0;
	
	for(i=0;i<=N;i=i+4){
    	sum = sum + ( 1 / (float)(factorial(i)) );
    }
	
	
	printf("Sum of the series is: %f\n",sum);
	
	return 0;
}