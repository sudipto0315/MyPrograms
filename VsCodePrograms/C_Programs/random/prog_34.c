#include <stdio.h>
void function2(int n) {
	int i = 0;
	if (n > 1)
		function2(n - 1);
	for (i = 0; i < n; i++)
		printf(" * ");
}
void main() {
	function2(3);
}
