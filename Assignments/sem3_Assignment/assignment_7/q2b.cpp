#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    int adjMatrix[n][n]; // adjMatrix will be of size n*n (vertex*vertex);

    // Initialize the adjacency matrix with all zeros
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            adjMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
