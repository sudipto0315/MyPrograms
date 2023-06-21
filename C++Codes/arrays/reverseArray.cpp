#include <iostream>
using namespace std;

void rev(int arr[], int size)
{
    int front = 0;
    int end = size - 1;
    while (front < end)
    {
        int temp = arr[front];
        arr[front] = arr[end];
        arr[end] = temp;
        front++;
        end--;
    }
    cout<<"Array after reversing: ";
    for (int i = 0; i < size; i++)
    {
        cout<< arr[i];
    }
}
int main(int argc, char const *argv[])
{
    int size = 0;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    //user input
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter the "<<i<<" element: ";
        cin>>arr[i];
    }
    //printing the entered array
    cout<<"The entered array is: ";
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    rev(arr,size);
    cout<<endl;
    return 0;
}
