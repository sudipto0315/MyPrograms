#include <stdio.h>
void display();
int n = 5;
void main() {
	++n;
 	display();
}
void display() {
 	++n;
	printf("%d", n);
}