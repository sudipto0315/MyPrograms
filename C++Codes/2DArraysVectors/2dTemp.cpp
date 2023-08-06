#include<iostream>
using namespace std;
void inputElements(int *a,int n)//used for inserting each elements
{
        for (int j = 0; j < n; j++)
        {
           // cout<<"Enter the "<<i<<", "<<j<<" element: ";
            cin>>a[j];
        }
}
void printElements(int *array,int n)//used for printing each elements
{
        for (int j = 0; j < n; j++)
        {
            cout<<array[j]<<" ";
        }
        cout<<endl;
}
int main(int argc, char const *argv[])
{
    int m,n;
    cout<<"Enter the no of Rows: ";
    cin >> m;
    cout<<"Enter the no of Columns: ";
    cin >> n;
    int array[m][n];
    for(int i=0;i<m;i++)
    {
    inputElements(array[i],n);
    }
    for(int i=0;i<m;i++)
    {
    printElements(array[i],n);
    }
    return 0;
}