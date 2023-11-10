#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u); // if you want to create directed graph, then comment out this line
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

vector<int> shortestPath(vector<vector<int>> &adj, int startVertex, int V)
{
    vector<bool> vis(V, false);
    vector<int> level(V, -1);

    queue<int> q;
    q.push(startVertex);
    level[startVertex] = 0;
    vis[startVertex] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int neighbor : adj[curr])
        {
            if (!vis[neighbor])
            {
                q.push(neighbor);
                vis[neighbor] = true;
                level[neighbor] = level[curr] + 1;
            }
        }
    }
    return level;
}

int diameter(vector<vector<int>> &adj, int V)
{
    int maxDiameter = 0;
    for (int i = 0; i < V; i++)
    {
        vector<int> distances = shortestPath(adj, i, V);
        for (int j = 0; j < V; j++)
        {
            if (distances[j] > maxDiameter)
            {
                maxDiameter = distances[j];
            }
        }
    }
    return maxDiameter;
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

    cout << "Diameter is :- " << diameter(adj, V) << endl;
    return 0;
}
