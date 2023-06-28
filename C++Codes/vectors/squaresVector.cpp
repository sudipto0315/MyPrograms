#include<bits/stdc++.h>
using namespace std;
void squaresVector(vector<int> &v)
{
    int left_ptr=0;
    int right_ptr=v.size()-1;
    while (left_ptr <= right_ptr)
    {
        if (abs(v[left_ptr])>abs(v[right_ptr]))
        {
            swap(v[left_ptr],v[right_ptr]);
            right_ptr--;
        }
        else{
            left_ptr++;
        }
    }

    //now square the values in the vector and pushback them
    for (int i = 0; i < v.size(); i++)
    {
        v[i]=v[i]*v[i];
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
    squaresVector(v);
    for (int i = 0; i < size; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    
    return 0;
}
