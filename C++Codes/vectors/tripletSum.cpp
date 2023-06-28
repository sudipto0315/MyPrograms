//brute-force strategy //high time complexity
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(vector<int> &num, int n,int sum)
{
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (i != j && i != k && j != k &&(num[i] + num[j] + num[k] == sum))
                {
                    vector<int> temp = {num[i], num[j], num[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
int main()
{
    int n,sum;
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
    vector<vector<int>> result = triplet(nums, size,sum); //function call

    //printing the triplets
    cout<<"\nThe triplets are:"<<endl;
    for (const auto &vec : result)
    {
        for (const auto &num : vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
