#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to add an edge to the graph
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // Comment out for a directed graph
}

// Function to print the graph
void printGraph(const vector<vector<int>> &adj)
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

void dfs(int node, vector<vector<int>> &adj, vector<int> &vis)
{
    // mark the more as visited
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

int connectedComponents(vector<vector<int>> &adj, int V)
{
    vector<int> vis(V, 0);
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        // if the node is not visited
        if (!vis[i])
        {
            // counter to count the number of provinces
            count++;
            dfs(i, adj, vis);
        }
    }
    return count;
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
    cout <<"The no of connected components are: "<< connectedComponents(adj, V) << endl;

    return 0;
}
