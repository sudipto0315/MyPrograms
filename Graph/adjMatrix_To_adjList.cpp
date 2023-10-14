#include <iostream>
#include <vector>
using namespace std;

// Function to print the adjacency list
void printList(vector<vector<int>> &adj)
{
    int V = adj.size();
    for (int v = 0; v < V; v++)
    {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int neighbor : adj[v])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

// Function to convert adjacency matrix to adjacency list
vector<vector<int>> convert(int adjMatrix[][100], int V)
{
    vector<vector<int>> adjList(V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adjMatrix[i][j] != 0)
            {
                adjList[i].push_back(j);
            }
        }
    }
    return adjList;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    int adjMatrix[100][100]; // Assuming a maximum size for the adjacency matrix

    // Initialize the adjacency matrix with all zeros
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            adjMatrix[i][j] = 0;
        }
    }

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // if you want to create directed graph, then comment out this line
    }

    cout << "Graph representation:" << endl;
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;

    vector<vector<int>> adjList = convert(adjMatrix, n);
    cout << "Adjacency List: \n";
    printList(adjList);
    return 0;
}
