#include <stdio.h>
void main() {
	int a = 0;                
	{
		int a = 10;
		printf("%d",a);
		a++;
		{
			a = 20;
		}
		{
			printf(" %d",a);
			int a = 30;
				a++;
			printf(" %d",a++);
		}
		printf(" %d",a++);
	}
	printf(" %d",a);
}