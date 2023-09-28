#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    int profit, weight;

    item(int profit, int weight)
    {
        this->profit = profit;
        this->weight = weight;
    }
};

static bool compare(struct item a, struct item b)
{
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct item arr[], int n)
{
    // Sorting Item on basis of ratio
    sort(arr, arr + n, compare);
    double finalValue = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            finalValue += arr[i].profit;
        }
        else
        {
            finalValue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int W = 50;
    item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << fractionalKnapsack(W, arr, N)<<endl;
    return 0;
}