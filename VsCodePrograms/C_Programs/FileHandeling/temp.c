#include <stdio.h>
static void f(void ) {
int i = 5;
printf("%d ", i);
i++;
}
int main() {
f();
f();
return 0;
}