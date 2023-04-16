#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_LENGTH 50000
#define MAX_WORD_LENGTH 50
#define MAX_UNIQUE_WORDS 1000

// A struct to store the frequency and the word.
typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int main() {
    char paragraph[MAX_PARAGRAPH_LENGTH+1];
    printf("Enter a paragraph (maximum 50000 characters):\n");
    fgets(paragraph, MAX_PARAGRAPH_LENGTH+1, stdin);

    // Replace non-alphabetic characters with whitespace.
    for (int i = 0; i < strlen(paragraph); i++) {
        if (!isalpha(paragraph[i])) {
            paragraph[i] = ' ';
        }
    }
    printf("After removing non-alphabetic characters:\n%s\n", paragraph);

    // Convert all lowercase letters to uppercase letters.
    for (int i = 0; i < strlen(paragraph); i++) {
        paragraph[i] = toupper(paragraph[i]);
    }
    printf("After converting to uppercase:\n%s\n", paragraph);

    // Find unique words and their frequencies.
    WordFrequency wordFrequencies[MAX_UNIQUE_WORDS];
    int numUniqueWords = 0;
    char *word = strtok(paragraph, " ");
    while (word != NULL) {
        int found = 0;
        for (int i = 0; i < numUniqueWords; i++) {
            if (strcmp(word, wordFrequencies[i].word) == 0) {
                wordFrequencies[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordFrequencies[numUniqueWords].word, word);
            wordFrequencies[numUniqueWords].frequency = 1;
            numUniqueWords++;
        }
        word = strtok(NULL, " ");
    }

    // Sort the words in descending order of frequency.
    for (int i = 0; i < numUniqueWords-1; i++) {
        for (int j = i+1; j < numUniqueWords; j++) {
            if (wordFrequencies[i].frequency < wordFrequencies[j].frequency) {
                WordFrequency temp = wordFrequencies[i];
                wordFrequencies[i] = wordFrequencies[j];
                wordFrequencies[j] = temp;
            }
        }
    }

    // Print each word and its frequency in descending order of frequency.
    printf("Words and their frequencies in descending order:\n");
    for (int i = 0; i < numUniqueWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    // Command line interface for searching words.
    while (1) {
        printf("Enter a word to search (or 'exit' to quit): ");
        char searchWord[MAX_WORD_LENGTH+1];
        scanf("%s", searchWord);
        if (strcmp(searchWord, "exit") == 0) {
            break;
        }
        for (int i = 0; i < strlen(searchWord); i++) {
            searchWord[i] = toupper(searchWord[i]);
        }
        int found = 0;
        for (int i = 0; i < numUniqueWords; i++) {
            if (strcmp(searchWord, wordFrequencies[i].word) == 0) {
                printf("%s occurs %d times.\n", searchWord, wordFrequencies[i].frequency);
                found = 1;
                break;
            }
        }
    }
}
