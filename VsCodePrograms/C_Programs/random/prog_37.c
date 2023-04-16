#include <stdio.h>
void m(void);
void main() {
	m();
	printf("%d", x);
}
int x;
void m() {
	x = 4;
}