// find the difference between the sum of elements at even
// indices to the sum of elements at odd indices
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int size = 0;
    int evenSum = 0;
    int oddSum = 0;
    cout << "Enter the size of the element: ";
    cin >> size;
    // enter the elements
    vector<int> v(size);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the " << i << " element: ";
        cin >> v[i];
    }
    //find odd or even
    for(int i = 0;i<v.size();i++)
    {
        if(i%2==0)
            evenSum=evenSum+v[i];
        else
            oddSum=oddSum+v[i];
    }
    int difference = evenSum-oddSum;
    cout<<"The difference is: "<<difference;
    return 0;
}
