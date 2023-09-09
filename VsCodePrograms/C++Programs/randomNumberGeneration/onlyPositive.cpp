#include <iostream>
#include <limits.h>
#include <time.h>
#include <random>
using namespace std;
int main(int argc, char const *argv[])
{
    //The following code will randomly generate only positive numbers
    int n=0;
    srand((unsigned)time(0));
    // srand(static_cast<unsigned>(time(0)));
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int rnd = rand() % 100 + 1; //this will generate only positive numbers
        arr[i] = rnd;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}
