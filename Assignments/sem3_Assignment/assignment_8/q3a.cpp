#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFS(const vector<vector<int>> &adj, vector<bool> &visited, int v)
{
    visited[v] = true;

    for (int neighbor : adj[v])
    {
        if (!visited[neighbor])
        {
            DFS(adj, visited, neighbor);
        }
    }
}

bool isConnected(const vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);

    // Find the first unvisited vertex
    int start_vertex = -1;
    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            start_vertex = v;
            break;
        }
    }

    // If all vertices are visited, the graph is connected
    if (start_vertex == -1)
    {
        return true;
    }

    // Otherwise, perform DFS from the first unvisited vertex
    DFS(adj, visited, start_vertex);

    // Check if all vertices are visited
    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            return false; // The graph is not connected
        }
    }

    return true; // The graph is connected
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    if (isConnected(adj))
    {
        cout << "The graph is connected." << endl;
    }
    else
    {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
