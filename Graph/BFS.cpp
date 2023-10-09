#include <iostream>
#include <vector>
#include <queue>
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

void BFS(const vector<vector<int>> &adj, int s, int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);

    // Create a queue for BFS using std::queue
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push(s);

    while (!queue.empty())
    {
        // Dequeue a vertex from the queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop();

        // Get all adjacent vertices of the dequeued vertex s.
        // If an adjacent has not been visited, then mark it visited and enqueue it
        for (auto adjacent : adj[s])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push(adjacent);
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
    printGraph(adj);

    int startingVertex;
    cout << "Enter the vertex from where to start the BFS Traversal: ";
    cin >> startingVertex;
    cout << "Following is Breadth First Traversal (starting from vertex " << startingVertex << ") \n";

    BFS(adj, startingVertex, V);

    return 0;
}
