#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // if you want to create directed graph, then comment out this line
}

void DFS(const vector<vector<int>> &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);

    cout << "Depth First Traversal: " << endl;

    for (int v = 0; v < V; ++v)
    {
        if (!visited[v])
        {
            cout << "Connected Component: ";
            vector<int> parent(V, -1);
            stack<int> stack;
            stack.push(v);

            while (!stack.empty())
            {
                v = stack.top();
                stack.pop();
                if (!visited[v])
                {
                    visited[v] = true;
                    cout << v << " ";
                    for (int neighbor : adj[v])
                    {
                        if (!visited[neighbor])
                        {
                            parent[neighbor] = v;
                            stack.push(neighbor);
                        }
                    }
                }
            }

            cout << endl;

            cout << "DFS Tree:" << endl;
            for (int i = 0; i < V; ++i)
            {
                if (parent[i] != -1)
                {
                    cout << parent[i] << " is the parent of: " << i << endl;
                }
            }
        }
    }
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
    // For printing the graph
    for (int i = 0; i < V; ++i)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int neighbor : adj[i])
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    cout << "DFS Traversal for connected and disconnected graphs:" << endl;
    DFS(adj);

    return 0;
}
