#include <stdio.h>
#include <string.h>

int searchIndex(char str[][25], int count, char search[100]) {
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(str[i], search) == 0) {
            return i;
        }
    }
    return -1; // Return -1 if search string is not found
}

int main() {
    char strings[][25] = {"apple", "banana", "orange", "kiwi", "mango"};
    int count = sizeof(strings) / sizeof(strings[0]);

    char search[100];
    printf("Enter the search string: ");
    scanf("%s", search);

    int index = searchIndex(strings, count, search);

    if (index != -1) {
        printf("The first occurrence of \"%s\" is found at index %d.\n", search, index);
    } else {
        printf("The search string \"%s\" was not found.\n", search);
    }

    return 0;
}
