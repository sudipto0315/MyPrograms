// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int sumIndex(vector<int> &v, int left_Ptr, int right_Ptr)
{
    int sum = 0;
    for (int i = left_Ptr; i <= right_Ptr; i++)
    {
        sum += v[i];
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int size, left_Ptr, right_Ptr = 0;
    cout << "Enter the size of the element: ";
    cin >> size;
    // enter the elements
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> v[i];
    }
    cout << "Enter the left pointer: ";
    cin >> left_Ptr;
    cout << "Enter the right pointer: ";
    cin >> right_Ptr;

    int sum = sumIndex(v, left_Ptr, right_Ptr);

    cout << "The sum of elements between the index L and R is: "<<sum<<endl;

        return 0;
}
