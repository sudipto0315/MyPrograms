#include <iostream>
#include <vector>
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
    // adj[v] = newNode(u, adj[v]);
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

void get_in_degree(Node adj[], int V, int in_degrees[])
{
    for (int i = 0; i < V; i++)
    {
        in_degrees[i] = 0;
    }

    for (int v = 0; v < V; v++)
    {
        for (Node neighbor = adj[v]; neighbor != NULL; neighbor = neighbor->next)
        {
            int vertex = neighbor->data;
            ++in_degrees[vertex];
        }
    }
}

void get_out_degree(Node adj[], int V, int out_degrees[])
{
    for (int i = 0; i < V; i++)
    {
        out_degrees[i] = 0;
    }

    for (int v = 0; v < V; ++v)
    {
        Node neighbor = adj[v];
        while (neighbor)
        {
            out_degrees[v]++;
            neighbor = neighbor->next;
        }
    }
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

    int in_degrees[V];
    get_in_degree(adj, V, in_degrees);

    // You can print the in-degrees here
    cout << "In-degrees of vertices:" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << in_degrees[i] << endl;
    }
    cout << endl;

    int out_degrees[V];
    get_out_degree(adj, V, out_degrees);

    // You can print the out-degrees here
    cout << "Out-degrees of vertices:" << endl;
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << out_degrees[i] << endl;
    }

    return 0;
}
