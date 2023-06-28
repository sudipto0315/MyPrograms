#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index1;
    int index2;
} Result;

Result iceCreamParlor(int m, int cost[], int n) {
    // Create a hash map to store the prices of ice cream flavors
    int hashMap[10001] = {0}; // Assuming the maximum cost is 10000

    Result result;
    result.index1 = -1;
    result.index2 = -1;

    for (int i = 0; i < n; i++) {
        int currentCost = cost[i];
        int remainingCost = m - currentCost;

        // Check if we have seen a flavor with the remaining cost before
        if (remainingCost >= 0 && hashMap[remainingCost] != 0) {
            result.index1 = hashMap[remainingCost] - 1; // Subtract 1 for 0-based indexing
            result.index2 = i;
            break;
        }

        // Update the hash map with the current flavor's cost and index
        hashMap[currentCost] = i + 1; // Add 1 for 1-based indexing
    }

    return result;
}

int main() {
    int m;
    printf("Enter the amount of money they have to spend: ");
    scanf("%d", &m);

    int n;
    printf("Enter the number of flavors: ");
    scanf("%d", &n);

    int cost[n];
    printf("Enter the cost of each flavor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);
    }

    Result result = iceCreamParlor(m, cost, n);

    if (result.index1 != -1 && result.index2 != -1) {
        printf("The two flavors that meet the criteria: indices %d and %d\n", result.index1, result.index2);
    } else {
        printf("No two flavors found that meet the criteria.\n");
    }

    return 0;
}
