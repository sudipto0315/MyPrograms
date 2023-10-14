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

// Function to add an edge to the graph
void addEdge(Node adj[], int u, int v)
{
    adj[u] = newNode(v, adj[u]);
    adj[v] = newNode(u, adj[v]); // if you want to create a directed graph, then comment out this line
}

// Function to print the graph
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

bool isGraphConnected(Node adj[], int V)
{
    // Create an array to mark visited vertices
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Use a stack for DFS traversal
    int stack[V];
    int top = -1;

    // Start DFS from the first vertex (vertex 0)
    stack[++top] = 0;
    visited[0] = true;

    while (top != -1)
    {
        int u = stack[top--];

        // Visit all adjacent vertices of u
        Node neighbor = adj[u];
        while (neighbor != NULL)
        {
            int v = neighbor->data;
            if (!visited[v])
            {
                stack[++top] = v;
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
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    Node adj[V];
    for (int i = 0; i < V; ++i)
    {
        adj[i] = NULL; // Initialize each adjacency list as empty
    }

    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges (vertex pairs):\n");
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    printf("Graph representation:\n");
    printGraph(adj, V);
    printf("\n");

    if (isGraphConnected(adj, V))
        printf("The graph is connected.\n");
    else
        printf("The graph is not connected.\n");

    return 0;
}
