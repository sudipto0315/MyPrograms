#include <stdio.h>
int decToBinary(int n)
{
	for (int i = 32; i >= 0; i--) {
		int k = n >> i; // right shift
		if (k & 1) // helps us know the state of first bit
			printf("1");
		else printf("0");
	}
}

// driver code
int main()
{
	int n = 987;
	decToBinary(n);
}
