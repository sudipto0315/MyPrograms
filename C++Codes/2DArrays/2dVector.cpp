#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the no of Rows: ";
    cin >> m;
    cout<<"Enter the no of Columns: ";
    cin >> n;
//1st approach(time complexity O(n) for creating the 2d vector)

//By using a for loop we are resizing the vector to its "n" size;
//By default its creating a "m" size vector with each of its inside elements a vector of size '0'.
//Then we resize the element vectors to its provided size "n";

    //code1
    /*
    // vector<vector<int>> array(m);
    // for(int i=0;i<m;i++)
    // {
    //     array[i].resize(n);
    // }
    */
    
//2nd approach(Simplier Approach O(1) for creating the 2d vector)

//here we are initialising the vector with a initial value to make it a 2d matrix
//so at first a vector of size "m" is getting created with its internal elements of size "initial_value"
//Then we are extending the inside elements of "initial_value" size by the user inserted values

    //code2
    int initial_value = 1; // replace 1 with the value you want to initialize all elements to
    vector<vector<int>> array(m, vector<int>(n, initial_value)); // creates an m x n 2D vector with all elements set to initial_value


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
