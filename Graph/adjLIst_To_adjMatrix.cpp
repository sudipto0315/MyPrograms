#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // if you want to create directed graph, then comment out this line
}

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

// Function to convert adjacency
// list to adjacency matrix
vector<vector<int>> convert(vector<vector<int>> &adj, int V)
{
    vector<vector<int>> matrix(V, vector<int>(V, 0));
    for (int v = 0; v < V; v++)
    {
        for (int neighbour : adj[v])
            matrix[v][neighbour] = 1;
    }
    return matrix;
}

// Function to display adjacency matrix
void printMatrix(vector<vector<int>> adj, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << adj[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adjList(V);

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adjList, u, v);
    }

    cout << "Graph representation:" << endl;
    printList(adjList);
    cout<<endl;
    vector<vector<int>> adjMatrix = convert(adjList, V);
    cout << "Adjacency Matrix: \n";
    printMatrix(adjMatrix, V);
    return 0;
}