#include <stdio.h>

int main()
{
	int i, j, k, rows, aphabetAscii = 64;

	printf("enter size = ");
	scanf("%d", &rows);
	for (i = 1 ; i <= rows; i++ ) 
	{
		for (j = 1 ; j <= rows - i; j++ ) 
		{
			printf(" ");	
		}
		for (k = 1 ; k <= i * 2 - 1; k++ ) 
		{
			printf("%c", aphabetAscii + k);
		}
		printf("\n");
	}
		
	for (i = rows - 1 ; i > 0; i-- ) 
	{
		for (j = 1 ; j <= rows - i; j++ ) 
		{
			printf(" ");
		}
		for (k = 1 ; k <= i * 2 - 1; k++ ) 
		{
			printf("%c", aphabetAscii + k);
		}
		printf("\n");
	}
}