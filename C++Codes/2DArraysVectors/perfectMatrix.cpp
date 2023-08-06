#include <iostream>
#include <vector>
using namespace std;

void inputElements(vector<vector<int>> &array, int m, int n) // used for inserting each elements
{
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

bool check(vector<vector<int>> &mat)
{
    int row = mat.size();
    int column = mat[0].size();
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < column; j++)
        {
            if (mat[i][j] != mat[i - 1][j - 1])
            {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int m, n;
    cout << "Enter the no of Rows: ";
    cin >> m;
    cout << "Enter the no of Columns: ";
    cin >> n;
    vector<vector<int>> array(m, vector<int>(n, 0));
    inputElements(array, m, n);
    if (check(array))
    {
        cout << "TRUE, the matrix is a perfect matrix."<<endl;
    }
    else
    {
        cout << "FALSE, the matrix is not a perfect matrix."<<endl;
    }
    return 0;
}
