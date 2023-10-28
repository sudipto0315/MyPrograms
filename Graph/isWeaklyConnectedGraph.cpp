#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to add an edge to the directed graph
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
}

void addUndirectedEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to print the directed graph
void printGraph(const vector<vector<int>>& adj) {
    int V = adj.size();
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int neighbor : adj[v]) {
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

vector<vector<int>> findUndirectedGraph(vector<vector<int>> &adj, int V)
{
    vector<vector<int>> undirectedGraph(V);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            addUndirectedEdge(undirectedGraph, u, v);
        }
    }
    return undirectedGraph;
}

int main(int argc, char const *argv[]) {
    int V, E;
    
    cout << "Enter the number of vertices: ";
    cin >> V;
    
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);

    cout << "Enter the edges (from vertex to vertex):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    cout << "Graph representation:" << endl;
    printGraph(adj);

    vector<vector<int>> undirectedGraph = findUndirectedGraph(adj,V);
    cout << "The undirected Graph is:" << endl;
    printGraph(undirectedGraph);
    if (isGraphConnected(undirectedGraph)==true)
    {
        cout<<"The graph is weakly connected !!";
    }
    else if (isGraphConnected(undirectedGraph)==false)
    {
        cout<<"The graph is not connected !!";
    }
    
    return 0;
}
