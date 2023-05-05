#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = "Hello, world!";
  str[0] = 'h'; // This line will cause a segmentation fault
  return 0;
}