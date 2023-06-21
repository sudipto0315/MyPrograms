//find the position of the last occurence of a elemant x.
#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    //enter the elements of the vector
    vector<int> v(6);
    for(int i=0;i<6;i++)
    {
        cin>>v[i];
    }
    //enter the element to find
    cout<<"Enter the element: ";
    int x;
    cin>>x;
    //find the occurence
    int occurence,occurence2=-1;
    //traversing from the first
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==x)
        {
            occurence = i;
        }
    }
    //traversing from the last (better approach)
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i]==x)
        {
            occurence2 = i;
            break;
        }
    }
    cout<<occurence<<endl;
    cout<<occurence2<<endl;
    return 0;
}
