#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // if you want to create directed graph, then comment out this line
}

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

bool isCyclic(vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    for (int v = 0; v < V; v++)
    {
        if (!visited[v])
        {
            visited[v] = true;
            vector<int> stack;
            stack.push_back(v);
            while (!stack.empty())
            {
                int u = stack.back();
                stack.pop_back();
                for (int i = 0; i < adj[u].size(); i++)
                {
                    int w = adj[u][i];
                    if (!visited[w])
                    {
                        visited[w] = true;
                        parent[w] = u;
                        stack.push_back(w);
                    }
                    else if (parent[u] != w)
                        return true;
                }
            }
        }
    }
    return false;
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
    if (isCyclic(adj, V))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph does not contain cycle\n";
    return 0;
}
