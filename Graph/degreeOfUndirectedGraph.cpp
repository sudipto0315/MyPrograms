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

void get_transpose(Node adj[], int V, Node transpose[])
{

    // Initialize the transpose graph with NULL adjacency lists
    for (int i = 0; i < V; i++)
    {
        transpose[i] = NULL;
    }

    // Traverse the original graph and add reverse edges to the transpose graph
    for (int v = 0; v < V; v++)
    {
        Node neighbor = adj[v];
        while (neighbor != NULL)
        {
            int vertex = neighbor->data;
            transpose[vertex] = newNode(v, transpose[vertex]);
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

    Node transpose[V];
    get_transpose(adj, V, transpose);

    cout << "The Transpose of the Graph is:" << endl;
    printGraph(transpose, V);
    cout << endl;
    return 0;
}
