#include <iostream>
#include <vector>
using namespace std;

/*
1. Transpose the matrix: Swap the element at position (i, j) with the 
   element at position (j, i) for all i and j. This will change rows 
   into columns.

2. Reverse each row: For each row in the transposed matrix, swap the 
   elements at the two ends (first and last) and move towards the center 
   until you reach the middle element.
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

void rotateMatrix(vector<vector<int>>& array) {
    int n = array.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            swap(array[i][j], array[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; ++i) {
        int left = 0, right = n - 1;
        while (left < right) {
            swap(array[i][left], array[i][right]);
            ++left;
            --right;
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
    rotateMatrix(array);
    cout << "Resultant Matrix:" << endl;
    printElements(array);

    return 0;
}