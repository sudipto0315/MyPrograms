#include <iostream>
#include <vector>
using namespace std;

/*
1. Create two arrays to keep track of the rows and columns that need to 
   be zeroed out.

2. Traverse the matrix and whenever you encounter a 0, mark the 
   corresponding row and column in the arrays.

3. Traverse the matrix again and for each element whose row or column is 
   marked, set it to 0.
*/

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

void setZero(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> zeroRows(m, false);
    vector<bool> zeroCols(n, false);

    // Step 1: Mark the rows and columns that need to be zeroed out
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                zeroRows[i] = true;
                zeroCols[j] = true;
            }
        }
    }

    // Step 2: Set the elements to 0 based on the marked rows and columns
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (zeroRows[i] || zeroCols[j]) {
                matrix[i][j] = 0;
            }
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
    setZero(array);
    cout << "Resultant Matrix:" << endl;
    printElements(array);

    return 0;
}