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
            triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
        }
        triangle[i][i] = 1; // Last element in each row is 1
    }
}

void printElements(vector<vector<int>> &array)
{
    int m = array.size();
    int n = array[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (array[i][j] != 0)//this if statement is to prevent printing the zeros
            {
                cout << array[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int m;
    cout << "Enter number of rows you want: ";
    cin >> m;

    vector<vector<int>> pascalsTriangle(m, vector<int>(m, 0)); // since no of = no of Column so m*m matrix

    generatePascalsTriangle(pascalsTriangle, m);
    printElements(pascalsTriangle);

    return 0;
}