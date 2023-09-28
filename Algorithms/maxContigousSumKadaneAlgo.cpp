#include <iostream>
#include <limits.h>
#include <time.h>
#include <random>
using namespace std;
int maxSubArraySum(int arr[], int size)
{
    int current_sum = 0, maximum_sum = 0;
    for (int i = 0; i < size; i++)
    {
        current_sum = current_sum + arr[i];
        if (current_sum > maximum_sum)
            maximum_sum = current_sum;

        if (current_sum < 0)
            current_sum = 0;
    }
    return maximum_sum;
}

int main(int argc, char const *argv[])
{
    int n=0;
    srand((unsigned)time(0));
    // srand(static_cast<unsigned>(time(0)));
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int rnd = rand() % 201 - 100; //this will generate both positive and negative numbers
        arr[i] = rnd;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    int size = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, size);
    cout << "Maximum contiguous sum is " << max_sum<<endl;
    return 0;
}
