// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
void sortZeroAndOnes(vector<int> &v)
{
    int left_ptr=0;
    int right_ptr=v.size()-1;
    while (left_ptr < right_ptr)
    {
        if (v[left_ptr]==1&&v[right_ptr]==0)
        {
            v[left_ptr]=0;
            v[right_ptr]=1;
            left_ptr++;
            right_ptr--;
        }
        if (v[left_ptr]==0)
        {
            left_ptr++;
        }
        if (v[right_ptr]==1)
        {
            right_ptr--;
        }
    }
    return;
}
int main(int argc, char const *argv[])
{
    int size = 0;
    cout<<"Enter the size of the element: ";
    cin>>size;
    //enter the elements
    vector<int> v(size);
    for (int i=0;i<size;i++)
    {
        cout<<"Enter the "<<i<<" element: ";
        cin>>v[i];
    }
    sortZeroAndOnes(v);
    for (int i = 0; i < size; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    
    return 0;
}
