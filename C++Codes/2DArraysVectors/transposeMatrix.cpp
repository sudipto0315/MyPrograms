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

void transposeMatrix(vector<vector<int>> &array, vector<vector<int>> &transpose)
{
    int m = array.size();
    int n = array[0].size();
        transpose.resize(n, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[i][j] = array[j][i];
        }
    }
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

    vector<vector<int>> transpose(m, vector<int>(n, 0));
    transposeMatrix(array,transpose);
    cout << "Resultant Matrix:" << endl;
    printElements(transpose);

    return 0;
}