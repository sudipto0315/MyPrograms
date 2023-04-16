#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main() {
  system("cls");
  int data[] = { 12, 11, 13, 5, 6 };
  int a = sizeof(data);
  int b = sizeof(data[0]);
  int size = sizeof(data) / sizeof(data[0]);
  printf("%d \n",a);
  printf("%d \n",b);
  printf("%d \n",size);
  getch();
}