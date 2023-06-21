//check if the given vector is sorted or not.
#include<iostream>
#include<vector>
using namespace std;
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
    //check for sorted vector
    bool sortedFlag = true;
    for(int i=0;i<v.size();i++)
    {
        if (v[i-1]>v[i])
        {
            sortedFlag = false;
            break;
        }
    }
    //output
    if(sortedFlag==true)
        cout<<"vector is sorted";
    else
        cout<<"The vector is not sorted";
    cout<<endl;
    return 0;
}
