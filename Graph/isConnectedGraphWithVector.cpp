#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Comment out for a directed graph
}

// Function to print the graph
void printGraph(const vector<vector<int>>& adj)
{
    for (int v = 0; v < adj.size(); ++v)
    {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int neighbor : adj[v])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

bool isGraphConnected(const vector<vector<int>>& adj)
{
    int V = adj.size();

    // Create an array to mark visited vertices
    vector<bool> visited(V, false);

    // Use a stack for DFS traversal
    stack<int> s;

    // Start DFS from the first vertex (vertex 0)
    s.push(0);
    visited[0] = true;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        // Visit all adjacent vertices of u
        for (int v : adj[u])
        {
            if (!visited[v])
            {
                s.push(v);
                visited[v] = true;
            }
        }
    }

    // If any vertex remains unvisited, the graph is not connected
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }

    return true;
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj(V);

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    cout << "Graph representation:" << endl;
    printGraph(adj);
    cout << endl;

    if (isGraphConnected(adj))
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;

    return 0;
}
