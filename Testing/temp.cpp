#include <iostream>
using namespace std;
int countStrings(int n)
{
    int a[n], b[n];
    a[0] = b[0] = 1;

    for (int i = 1; i < n; i++)
    {
        a[i] = a[i-1] + b[i-1];
        b[i] = a[i-1];
    }

    return a[n-1] + b[n-1];
}

int main()
{
    //int n = 5;
    // cout << "Number of binary strings of length " << n
    //      << " with no consecutive 1's: " << countStrings(n) << endl;
    int n,t;
    while (t--)
    {
        cin>>n;
        countStrings(n);
    }
    return 0;
}
