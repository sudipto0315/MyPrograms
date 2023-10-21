#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
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

bool isBipartite(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> color(n); // 0: uncolored; 1: color A; -1: color B

    queue<int> q; // queue, resusable for BFS

    for (int i = 0; i < n; i++)
    {
        if (color[i])
            continue; // skip already colored nodes

        // BFS with seed node i to color neighbors with opposite color
        color[i] = 1; // color seed i to be A (doesn't matter A or B)
        for (q.push(i); !q.empty(); q.pop())
        {
            int cur = q.front();
            for (int neighbor : adj[cur])
            {
                if (!color[neighbor]) // if uncolored, color with opposite color
                {
                    color[neighbor] = -color[cur];
                    q.push(neighbor);
                }

                else if (color[neighbor] == color[cur])
                    return false; // if already colored with same color, can't be bipartite!
            }
        }
    }

    return true;
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

    bool result = isBipartite(adj);
    if (result)
    {
        cout << "Yes, the graph is Bipartite." << endl;
    }
    else
    {
        cout << "No, the graph is not Bipartite." << endl;
    }

    return 0;
}
