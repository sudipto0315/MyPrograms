#include <iostream>
#include <vector>
using namespace std;
int longestSequence(vector<int>& v,int size) {
    int zeroCounter, oneCounter, index = 0;
    for (int i = 0; i <= size; i++)
    {
        if(v[i]==0)
        {
            zeroCounter++;
        }
        if(v[i]==1)
        {
            oneCounter++;
        }
        if(zeroCounter==oneCounter)
        {
            index=i;
        }
    }
    
    return index;
}

int main(int argc, char const *argv[])
{
    int size= 0;
    cout << "Enter the size of the element: ";
    cin >> size;
    // enter the elements
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> v[i];
    }
    int index = longestSequence(v,size);
    cout << "Longest 0 1 Sequence is: ";
    for (int i = 0; i <= index; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}