#include <stdio.h>
int main() {
  // //clrscr();
  // int a=8;
  // printf("%i\n",a<<1);
  // return 0;
  int a=10;
  int *ptr=&a;
  int **pptr=&ptr;
  printf("%d %d %d %d %d",a,*ptr,ptr,*pptr,**pptr);
  return 0;
}