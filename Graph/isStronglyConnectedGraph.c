#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node_t Node_t;
typedef struct Node_t *Node;

struct Node_t
{
    int data;
    Node next;
};

Node newNode(int data, Node next)
{
    Node node = (Node) calloc(1, sizeof (Node_t));
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
        printf("Adjacency list of vertex %d: ", v);
        Node neighbor = adj[v];
        while (neighbor)
        {
            printf("%d ", neighbor->data);
            neighbor = neighbor->next;
        }
        printf("\n");
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

int main()
{
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    Node adj[V];
    Node transpose[V];
    for (int i = 0; i < V; i++)
    {
        adj[i] = NULL; // Initialize each adjacency list as empty
        transpose[i] = NULL;
    }

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addReverseEdge(transpose, v, u); // Create the transpose graph
    }

    printf("Original Graph: \n");
    printGraph(adj, V);
    printf("\n");

    printf("Transpose Graph: \n");
    printGraph(transpose, V);
    printf("\n");

    if (isStronglyConnected(adj, transpose, V))
        printf("The graph is strongly connected.\n");
    else
        printf("The graph is not strongly connected.\n");

    return 0;
}
