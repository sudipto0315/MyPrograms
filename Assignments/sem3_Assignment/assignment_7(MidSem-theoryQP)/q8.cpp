#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter the number of rows" << endl;
    cin >> n;
    cout << "Enter the number of columns" << endl;
    cin >> m;
    int a[n][m];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int b[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i][j] = 1;
        }
    }
    // b[n-1][m-1]=1;
    for (int j = m - 2; j >= 0; j--)
    {
        if (a[n - 1][j] > a[n - 1][j + 1])
            b[n - 1][j] = b[n - 1][j + 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i][m - 1] > a[i + 1][m - 1])
            b[i][m - 1] = b[i + 1][m - 1] + 1;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if (a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1])
                b[i][j] = 1 + max(b[i][j + 1], b[i + 1][j]);
            else if (a[i][j] > a[i + 1][j] && a[i][j] < a[i][j + 1])
                b[i][j] = 1 + b[i + 1][j];
            else if (a[i][j] < a[i + 1][j] && a[i][j] > a[i][j + 1])
                b[i][j] = 1 + b[i][j + 1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] >= max)
                max = b[i][j];
        }
    }
    cout << "Max length is " << max << endl;
    return 0;
}