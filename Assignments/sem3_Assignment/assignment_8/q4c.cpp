#include <iostream>
#include <vector>
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

void addEdge(Node adj[], int u, int v)
{
    adj[u] = newNode(v, adj[u]);
}

void addReverseEdge(Node transpose[], int u, int v)
{
    transpose[u] = newNode(v, transpose[u]);
}

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

void DFS_Recursive(Node adj[], int V, int vertex, bool visited[])
{
    visited[vertex] = true;
    Node neighbor = adj[vertex];
    while (neighbor != NULL)
    {
        int v = neighbor->data;
        if (!visited[v])
            DFS_Recursive(adj, V, v, visited);
        neighbor = neighbor->next;
    }
}

bool isStronglyConnected(Node adj[], Node transpose[], int V)
{
    // Step 1: Initialize all vertices as not visited for both the original and transpose graphs
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Step 2: Perform DFS starting from the first vertex in the original graph
    DFS_Recursive(adj, V, 0, visited);

    // If any vertex remains unvisited, the graph is not strongly connected
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }

    // Step 3: Reset visited array for the transpose graph
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Step 4: Perform DFS starting from the first vertex in the transpose graph
    DFS_Recursive(transpose, V, 0, visited);

    // If any vertex remains unvisited, the graph is not strongly connected
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            return false;
    }

    // If all vertices are visited in both the original and transpose graphs, it's strongly connected
    return true;
}

int main(int argc, char const *argv[])
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Node adj[V];
    Node transpose[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL; // Initialize each adjacency list as empty
        transpose[i] = NULL;
    }

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
        addReverseEdge(transpose, v, u); // Create the transpose graph
    }

    cout << "Original Graph: " << endl;
    printGraph(adj, V);
    cout << endl;

    cout << "Transpose Graph: " << endl;
    printGraph(transpose, V);
    cout << endl;

    if (isStronglyConnected(adj, transpose, V))
        cout << "The graph is strongly connected." << endl;
    else
        cout << "The graph is not strongly connected." << endl;

    return 0;
}
