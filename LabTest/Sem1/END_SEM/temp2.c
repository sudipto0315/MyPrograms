#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_SIZE 50000

typedef struct{
    char word[MAX_SIZE];
    int freq;
} WordFrequency;

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

int main() {
   char s[MAX_SIZE], output2[MAX_SIZE];
   printf("Enter a string : ");
   gets(s);
   RemoveCharWithWhitespace(s,output2);
   printf("\nAfter removing Non-English Alphabets: %s\n", output2);
   LowerToUpper(output2);


    WordFrequency WordFreq[MAX_SIZE];
    int numUniqueWords = 0;
    char *word = strtok(output2," ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < numUniqueWords; i++) {
            if (strcmp(word, WordFreq[i].word) == 0) {
                WordFreq[i].freq++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(WordFreq[numUniqueWords].word, word);
            WordFreq[numUniqueWords].freq = 1;
            numUniqueWords++;
        }
        word = strtok(NULL, " ");
    }
    for (int i = 0; i < numUniqueWords-1; i++) {
        for (int j = i+1; j < numUniqueWords; j++) {
            if (WordFreq[i].freq < WordFreq[j].freq) {
                WordFrequency temp = WordFreq[i];
                WordFreq[i] = WordFreq[j];
                WordFreq[j] = temp;
            }
        }
    }
    printf("Words and their frequencies in descending order:\n");
    for (int i = 0; i < numUniqueWords; i++) {
        printf("%s: %d\n", WordFreq[i].word, WordFreq[i].freq);
    }
   return 0;
}