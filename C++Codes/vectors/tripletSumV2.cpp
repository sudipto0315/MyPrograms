// Hashmap strategy //n^2 complexity //better approach than Brute-Force
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(vector<int> &num, int n, int sum)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = (sum - (num[i] + num[j]));
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {num[i], num[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(num[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    int n, sum;
    cout << "Enter the size of the vector: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements in the vector: ";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> nums[i];
    }

    // Input k value
    cout << "Enter the value of sum: ";
    cin >> sum;

    int size = nums.size();
    vector<vector<int>> result = triplet(nums, size, sum); // function call

    // printing the triplets
    cout << "\nThe triplets are:" << endl;
    for (const auto &vec : result)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < result.size(); i++)
    {
        vector<int> vec = result[i];
        for (int j = 0; j < vec.size(); j++)
        {
            int num = vec[j];
            // Do something with num
        }
    }

    return 0;
}
