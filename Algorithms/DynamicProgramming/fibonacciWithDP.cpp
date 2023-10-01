#include <iostream>
#include <vector>
using namespace std;

int fibo(int n)
{
    int value = 0;
    if (n == 0 || n == 1)
    {
        value = n;
    }
    else
    {
        value = fibo(n - 1) + fibo(n - 2);
    }
    return value;
}
int topDownDP_InLinearSpace(int n, vector<int> &memo)
{
    if (memo[n] != -1)
    {
        return memo[n];
    }

    int result;
    if (n == 0 || n == 1)
    {
        result = n;
    }
    else
    {
        result = topDownDP_InLinearSpace(n - 1, memo) + topDownDP_InLinearSpace(n - 2, memo);
    }
    memo[n] = result;
    return result;
}

int bottomUpDP_InConstantSpace(int n){
    if (n==0||n==1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++)
    {
        int temp = a+b;
        a=b;
        b=temp;
    }
    
    return b;
}
int main(int argc, char const *argv[])
{
    cout << "Enter the value of n: ";
    int n;
    cin >> n;
    cout << "using brute-force:" << fibo(n)<<endl;
    vector<int> memo(n + 1, -1);
    cout << "Bottom up DP: " << topDownDP_InLinearSpace(n, memo)<<endl;
    cout << "Bottom up DP with constant space complexity: " << bottomUpDP_InConstantSpace(n)<<endl;
    return 0;
}
