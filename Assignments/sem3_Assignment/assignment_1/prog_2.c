#include <stdio.h>
#include <math.h>

int doCeil(double x) {
    int result = (int)x; // Truncate the decimal part
    if (x > result) {
        result += 1; // Increment if x has a non-zero decimal part
    }
    return result;
}

int calculateAVLMaxHeight(int numNodes) {
    int prev1 = 0, prev2 = 1, current = 1;
    int height = 0;

    while (current < numNodes) {
        current = prev1 + prev2 + 1;
        prev1 = prev2;
        prev2 = current;
        height++;
    }

    return height;
}

int calculateAVLMinHeight(int numNodes) {
    double temp = (log2(numNodes + 1)) - 1;
    return doCeil(temp);
}

int main() {
    int numNodes;
    printf("Enter the number of nodes in the AVL tree: ");
    scanf("%d", &numNodes);

    int maxHeight = calculateAVLMaxHeight(numNodes);
    printf("The maximum height of the AVL tree with %d nodes is: %d\n", numNodes, maxHeight);

    int minHeight = calculateAVLMinHeight(numNodes);
    printf("The minimum height of the AVL tree with %d nodes is: %d\n", numNodes, minHeight);

    return 0;
}
