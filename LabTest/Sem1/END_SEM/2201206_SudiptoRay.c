#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE 50000
int RemoveCharWithWhitespace(char s[],char output2[]){
for(int i=0; s[i] != '\0'; i++) {
      if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
         output2[i] = s[i];
      } else {
         output2[i] = ' ';
      }
   }
   return 0;
}
int LowerToUpper(char output2[]){
    for (int i = 0; output2[i]!='\0'; i++) {
      if(output2[i] >= 'a' && output2[i] <= 'z') {
         output2[i] = output2[i] - 32;
      }
   }
   return 0;
}
// int unique(a[]){
//    int i = 0, e, j, d, k, space = 0;
//     char a[MAX_SIZE], b[15][20], c[15][20];
//     for (i = 0;a[i] != '\0';i++)        //loop to count no of words
//     {
//         if (a[i] == ' ')
//             space++;
//     }
//     i = 0;
//     for (j = 0;j<(space + 1);i++, j++)
//     {
//         k = 0;
//         while (a[i] != '\0')
//         {
//             if (a[i] == ' ')
//             {
//                 break;
//             }
//             else
//             {
//                 b[j][k++] = a[i];
//                 i++;
//             }
//         }
//         b[j][k] = '\0';
//     }
//     i = 0;
//     strcpy(c[i], b[i]);
//     for (e = 1;e <= j;e++)        //loop to check whether the string is already present in the 2D array or not
//     {
//         for (d = 0;d <= i;d++)
//         {
//             if (strcmp(c[i], b[e]) == 0)
//                 break;
//             else
//             {
//                 i++;
//                 strcpy(c[i], b[e]);
//                 break;
//             }
//         }
//     }
//     printf("\nNumber of unique words in %s are:%d", a, i);
//     return 0;
//}
int main() {
   char s[MAX_SIZE], output2[MAX_SIZE];
   printf("Enter a string : ");
   gets(s);
   RemoveCharWithWhitespace(s,output2);
   printf("\nAfter removing Non-English Alphabets: %s\n", output2);
   LowerToUpper(output2);
   printf("%s",output2);
   //unique(output2);
   return 0;
}