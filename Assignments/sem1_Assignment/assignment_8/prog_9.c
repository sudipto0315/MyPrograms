#include <stdio.h>

void findFrequency(int arr[], int length) {
    int fr[length];
    int visited = -1;
    
    for (int i = 0; i < length; i++) {
        int count = 1;
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                count++;
                fr[j] = visited;
            }
        }
        if (fr[i] != visited) {
            fr[i] = count;
        }
    }

    printf("---------------------\n");
    printf(" Element | Frequency\n");
    printf("---------------------\n");
    for (int i = 0; i < length; i++) {
        if (fr[i] != visited) {
            printf("    %d    |    %d\n", arr[i], fr[i]);
        }
    }
}

int main() {
    int arr[] = {3, 2, 3, -1, 4, -4, 5, 5, 6, 7};
    int length = sizeof(arr) / sizeof(arr[0]);

    findFrequency(arr, length);

    return 0;
}
