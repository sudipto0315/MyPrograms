//count the number of elements strictly greater than a value x.
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int size;
    cout<<"Enter the size of the vector: ";
    cin>>size;
    cout<<"Enter the elements: ";
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cin>>v[i];
    }

    //enter the element to count total no of occurences
    cout<<"enter the element: ";
    int x;
    cin>>x;

    int occurence = 0;
    for(int i =0 ; i<v.size();i++)
    {
        if(v[i]>x)
        {
            occurence++;
        }
    }

    cout<<"The total no of occurences are: "<<occurence<<endl;
    
    return 0;
}
