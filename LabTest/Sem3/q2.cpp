#include <iostream>
#include <vector>
using namespace std;
int longestIncreasingSubsequence(vector<int> &nums, int d)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] - nums[j] >= d)
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxLength = max(maxLength, dp[i]);
            }
        }
    }
    // printing the dp vector
    cout<<"The DP vector is: ";
    for (int i = 0; i < dp.size(); i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    
    return maxLength;
}

int main(int argc, char const *argv[])
{
    int n, d;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter the minimum difference (d): ";
    cin >> d;

    int length = longestIncreasingSubsequence(nums, d);
    cout << "Length of the longest increasing subsequence is: " << length << endl;
    return 0;
}
