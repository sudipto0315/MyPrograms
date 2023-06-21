//rotating a given array by k steps
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 3;
    // k can be bigger than n
    if (k >= n)
        k = k % n;

    int ansArray[5];
    int j = 0;
    // inserting last k elements in ans array
    for (int i = n - k; i < n; i++)
    {
        ansArray[j++] = array[i];
    }

    // inserting the first n-k elements in ans array
    for (int i = 0; i <= n - k; i++)
    {
        ansArray[j++] = array[i];
    }

    // printing the array
    for (int i = 0; i < n; i++)
    {
        cout << ansArray[i];
    }
    cout << endl;
}
