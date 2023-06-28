#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int m,n;
    cin>>m>>n;

    int array[m][n];
    
    //input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
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
