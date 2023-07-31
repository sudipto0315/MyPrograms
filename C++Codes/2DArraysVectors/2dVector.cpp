#include <iostream>
#include <vector>
using namespace std;

void inputElements(vector<vector<int>> &array,int m,int n)//used for inserting each elements
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"Enter the "<<i<<", "<<j<<" element: ";
            cin>>array[i][j];
        }
    }
}

void printElements(vector<vector<int>> &array,int m,int n)//used for printing each elements
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int m,n;
    cout<<"Enter the no of Rows: ";
    cin >> m;
    cout<<"Enter the no of Columns: ";
    cin >> n;
//1st approach(time complexity O(n) for creating the 2d vector)

/*
    By using a for loop we are resizing the vector to its "n" size;
    By default its creating a "m" size vector with each of its inside elements a vector of size '0'.
    Then we resize the element vectors to its provided size "n";
*/


    //code1 START

    // vector<vector<int>> array(m);
    // for(int i=0;i<m;i++)
    // {
    //     array[i].resize(n);
    // }
    // inputElements(array,m,n);
    // printElements(array,m,n);
    
    //code1 END

//2nd approach(Simplier Approach O(1) for creating the 2d vector)

/*
    We create a 2D vector containing "m"
    elements each having the value "vector<int> (n, 0)".
    "vector<int> (n, 0)" means a vector having "n"
    elements each of value "0".
    Here these elements are vectors.
*/

/*
    here we are creating the 2d vector at once. So the creation takes O(1).
    Then we are changing the elements at each location to the user input value.
    This processes of changing values at each location takes time complexity O(m*n) 
*/


    //code2 START

    // vector<vector<int>> array(m, vector<int>(n, 0)); 
    // inputElements(array,m,n);
    // printElements(array,m,n);

    //code2 END
    
    return 0;
}
