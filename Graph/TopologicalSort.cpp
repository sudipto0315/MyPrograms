//Only Works on DAG (Directed Acyclic Graphs)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}

// Function to print the graph
void printGraph(const vector<vector<int>> &adj)
{
    int V = adj.size();
    for (int v = 0; v < V; ++v)
    {
        cout << "Adjacency list of vertex " << v << ": ";
        for (int neighbor : adj[v])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

void dfs(int node, vector<int> &visited, stack<int> &stack, vector<vector<int>> &adj)
{
    visited[node] = 1;
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, visited, stack, adj);
        }
    }
    stack.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &adj, int V)
{
    vector<int> visited(V, 0);
    stack<int> stack;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, stack, adj);
        }
    }

    vector<int> ans;
    while (!stack.empty())
    {
        ans.push_back(stack.top());
        stack.pop();
    }
    return ans;
}

int main(int argc, char const *argv[])
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
    vector<int> ans = topologicalSort(adj, V);

    for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

    return 0;
}