#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int m,n;
    cout<<"Enter the no of Rows: ";
    cin >> m;
    cout<<"Enter the no of Columns: ";
    cin >> n;

    int array[m][n];
    
    //input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"Enter the "<<i<<", "<<j<<" element: ";
            cin>>array[i][j];
        }
    }

    //printing
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}