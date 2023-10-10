#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // if you want to create directed graph, then comment out this line
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

void DFS(const vector<vector<int>> &adj, int startingVertex, int V)
{
    vector<bool> visited(V, false);
    vector<int> parent(V, -1);
    stack<int> stack;

    stack.push(startingVertex);

    cout << "Following is Depth First Traversal (starting from vertex " << startingVertex << "): ";

    while (!stack.empty())
    {
        int v = stack.top();
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
    cout<<"\n"<<endl;
    cout <<"DFS Tree:" << endl;
    for (int i = 0; i < V; ++i)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " is the parent of: " << i << endl;
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
    printGraph(adj);
    cout<<endl;
    int startingVertex;
    cout << "Enter the vertex from where to start the DFS Traversal: ";
    cin >> startingVertex;
    cout<<endl;

    DFS(adj, startingVertex, V);
    return 0;
}