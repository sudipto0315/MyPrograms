#include <iostream>
#include <vector>
using namespace std;

void generatePascalsTriangle(vector<vector<int>> &triangle, int n)
{
    for (int i = 0; i < n; i++)
    {
        triangle[i][0] = 1; // First element in each row is 1
        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle[i][i] = 1; // Last element in each row is 1
    }
}

void printElements(vector<vector<int>> &array)
{
    int m = array.size();
    int n = array[0].size();

    // Calculate the maximum width of a number in the last row for proper alignment
    int maxWidth = to_string(array[m - 1][n - 1]).length();

    for (int i = 0; i < m; i++)
    {
        // Indentation based on the level in the triangle
        int indentation = (m - i - 1) * (maxWidth + 1) / 2;

        // Left padding to center-align the row
        cout << string(indentation, ' ');

        for (int j = 0; j <= i; j++)
        {
            // Print each element with proper width
            cout.width(maxWidth);
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m;
    cout << "Enter number of rows you want: ";
    cin >> m;

    vector<vector<int>> pascalsTriangle(m, vector<int>(m, 0));

    generatePascalsTriangle(pascalsTriangle, m);
    printElements(pascalsTriangle);

    return 0;
}