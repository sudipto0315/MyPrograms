#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char const *argv[])
{
    cout<<"Enter the elements of the vector: ";
    vector<int>v;
    //vector<int>v(5);
    //for loop for input
    for (int i = 0; i < 5; i++)
    {
        int element;
        cin>>element;
        v.push_back(element);
        //cin>>v[i];
    }

    cout<<"Printing with for loop: ";
    
    //for loop for printing
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;  

    v.insert(v.begin()+2,7); // trying the insert and begin functions

    cout<<"Printing with for each loop: ";
    //for each loop
    for (int ele:v)
    {
        cout<<ele<<" ";
    }
    cout<<endl;

    v.erase(v.end()-2); //trying the erase and end function

    cout<<"Printing with while loop: ";
    //while loop
    int index=0;
    while(index < v.size())
    {
        cout<<v[index++]<<" ";
    }
    cout<<endl;
    return 0;
}
