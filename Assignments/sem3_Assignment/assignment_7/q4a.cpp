#include <iostream>
#include <stack>
using namespace std;

typedef struct Node_t Node_t;
typedef struct Node_t *Node;

struct Node_t
{
    int data;
    Node next;
};

Node newNode(int data, Node next)
{
    Node node = new Node_t;
    node->data = data;
    node->next = next;
    return node;
}

// Function to add an edge to the graph
void addEdge(Node adj[], int u, int v)
{
    adj[u] = newNode(v, adj[u]);
    adj[v] = newNode(u, adj[v]); // if you want to create directed graph, then comment out this line
}

// Function to print the graph
void printGraph(Node adj[], int V)
{
    for (int v = 0; v < V; ++v)
    {
        cout << "Adjacency list of vertex " << v << ": ";
        Node neighbor = adj[v];
        while (neighbor)
        {
            cout << neighbor->data << " ";
            neighbor = neighbor->next;
        }
        cout << endl;
    }
}

bool isGraphConnected(Node adj[], int V)
{
    // Create an array to mark visited vertices
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

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
        Node neighbor = adj[u];
        while (neighbor != NULL)
        {
            int v = neighbor->data;
            if (!visited[v])
            {
                s.push(v);
                visited[v] = true;
            }
            neighbor = neighbor->next;
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

int main(int argc, char const *argv[])
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    Node adj[V];
    for (int i = 0; i < V; ++i)
    {
        adj[i] = NULL; // Initialize each adjacency list as empty
    }

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
    printGraph(adj, V);
    cout << endl;

    if (isGraphConnected(adj, V))
        cout << "The graph is connected." << endl;
    else
        cout << "The graph is not connected." << endl;
    return 0;
}