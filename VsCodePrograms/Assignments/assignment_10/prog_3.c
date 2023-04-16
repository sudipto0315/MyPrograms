// Write a program in C to convert all lowercase characters to uppercase in a string.
#include <stdio.h>
#include <string.h>

int main() {
   char s[100];
   int i;
   printf("Enter a string : ");
   gets(s);

   for (i = 0; s[i]!='\0'; i++) {
      if(s[i] >= 'a' && s[i] <= 'z') {
         s[i] = s[i] - 32;
      }
   }
   printf("\nString in Upper Case = %s", s);
   return 0;
}