//Made By Pallav Kumar
#include <iostream>
#include <vector>
#include <time.h>
#include <random>
#include <algorithm>
using namespace std;

int select(vector<int> &A, int k)
{
    if (k > 0 && k <= A.size())
    {
        if (A.size() == 1)
            return A[0];
        if (A.size() <= 5)
        {
            sort(A.begin(), A.end());
            return A[k - 1];
        }

        vector<int> medians;
        for (int i = 0; i < A.size(); i += 5)
        {
            vector<int> subgrp;
            for (int j = i; j < i + 5 && j < A.size(); j++)
            {
                subgrp.push_back(A[j]);
            }
            sort(subgrp.begin(), subgrp.end());
            int fill = 0;
            for (int j = i; j < i + 5 && j < A.size(); j++)
            {
                A[j] = subgrp[fill++];
            }
            medians.push_back(subgrp[(subgrp.size() / 2)]);
        }

        int med = select(medians, medians.size() / 2);

        vector<int> X, Y;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] <= med)
            {
                X.push_back(A[i]);
            }
            else if (A[i] > med)
            {
                Y.push_back(A[i]);
            }
        }

        if (X.size() == k)
        {            return med;
        }
        else if (X.size() > k)
        {
            return select(X, k);
        }
        else
        {
            return select(Y, k - X.size());
        }
    }
    else
    {
        cout << "Not valid" << endl;
        return -1;
    }
}

int main()
{
    srand(time(0));
    // int k;
    // cout << "Enter size of array : " << endl;
    // cin >> k;
    vector<int> nums;

    for (int i = 0; i < 10; i++)
    {
        int rnd = rand() % 100 + 1;
        nums.push_back(rnd);
    }

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    int k;
    cout << "Enter kth value: " << endl;
    cin >> k;

    cout << k << " Smallest element is: " << select(nums, k) << endl;

    cout << endl;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
