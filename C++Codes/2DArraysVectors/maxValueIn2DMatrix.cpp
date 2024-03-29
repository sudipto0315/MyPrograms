#include <iostream>
#include <vector>
using namespace std;

void inputElements(vector<vector<int>> &array) // used for inserting each elements
{
    int m = array.size();
    int n = array[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Enter the " << i << ", " << j << " element: ";
            cin >> array[i][j];
        }
    }
}

void printElements(vector<vector<int>> &array) // used for printing each elements
{
    int m = array.size();
    int n = array[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int largest(vector<vector<int>>array)
{
    int m = array.size();
    int n = array[0].size();
    int max = array[0][0];
    for(int i=0 ; i<m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
            }
        }
    }
    return max;
}


int main()
{
    int m, n;

    cout << "Enter the dimensions Matrix:" << endl;
    cout << "Enter the no of Rows: ";
    cin >> m;
    cout << "Enter the no of Columns: ";
    cin >> n;
    vector<vector<int>> array(m, vector<int>(n, 0));
    cout << "Enter the Matrix:" << endl;
    inputElements(array);

    cout << "The entered Matrix is :" << endl;
    printElements(array);

    int largestElement = largest(array);
    cout<<"The largest value in the 2D Matrix is: "<<largestElement<<endl;

    return 0;
}