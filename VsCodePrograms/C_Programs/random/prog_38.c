#include <stdio.h>
int a, b, c = 0;
void prtFun(void);
int main() {
	static int a = 1;
	prtFun();
	a += 1;//2
	prtFun();
	printf("%d %d\n" , a, b) ;
}
  
void prtFun(void) {
	static int a = 2;
	int b = 1;
	a += ++b;
	printf("%d %d\n" , a, b);
}