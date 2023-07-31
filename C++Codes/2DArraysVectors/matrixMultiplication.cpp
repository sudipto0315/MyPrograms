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

void printElements(vector<vector<int>> &array)// used for printing each elements
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

void multiply(vector<vector<int>> &array1, vector<vector<int>> &array2, vector<vector<int>> &array3, int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < n; k++)
            {
                array3[i][j] += array1[i][k]*array2[k][j];
            }
            
        }
        
    }
    
}

int main()
{
    int m, n1, n2, p;

    cout << "Enter the dimensions 1st Matrix:" << endl;
    cout << "Enter the no of Rows: ";
    cin >> m;
    cout << "Enter the no of Columns: ";
    cin >> n1;
    cout << "Enter the dimensions 2nd Matrix:" << endl;
    cout << "Enter the no of Rows: ";
    cin >> p;
    cout << "Enter the no of Colum6ns: ";
    cin >> n2;

    if (n1 == n2 && m > 0 && n1 > 0 && p > 0)
    {
        int n = n1 = n2;
        vector<vector<int>> array1(m, vector<int>(n, 0));
        cout<<"Enter the 1st Matrix:"<<endl;
        inputElements(array1, m, n);

        vector<vector<int>> array2(n, vector<int>(p, 0));
        cout<<"Enter the 2nd Matrix:"<<endl;
        inputElements(array2, n, p);

        cout << "Matrix 1:" << endl;
        printElements(array1);
        cout << "Matrix 2:" << endl;
        printElements(array2);

        vector<vector<int>> array3(m, vector<int>(p, 0));
        multiply(array1,array2,array3,m,n,p);
        cout << "Resultant Matrix:" << endl;
        printElements(array3);
    }
    else
    {
        cout << "Invalid dimensions for matrix multiplication." << endl;
    }

    return 0;
}