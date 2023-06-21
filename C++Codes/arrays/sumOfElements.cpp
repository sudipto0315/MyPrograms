#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int len = 0;
    cout<<"Enter the size of the array: ";
    cin>>len;
    int arr[len];
    //user input
    for (int i = 0; i < len; i++)
    {
        cout<<"Enter the "<<i<<" element: ";
        cin>>arr[i];
    }
    //printing the entered array
    cout<<"The entered array is: ";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    //finding the sum
    int sum =0;
    for (int i = 0; i < len; i++)
    {
        sum = sum + arr[i];
    }
    cout<<sum<<endl;
    return 0;
}
