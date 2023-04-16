#include<stdio.h>
int main() {
   int a, b, i, hcf;
   a = 12;
   b = 16;
   for(i = 1; i <= a || i <= b; i++) {
   if( a%i == 0 && b%i == 0 )
      hcf = i;
   }
   printf("HCF = %d", hcf);
   printf("\n");
   printf("LCM = %d",(a*b)/hcf);
   printf("\n");   
   return 0;
}