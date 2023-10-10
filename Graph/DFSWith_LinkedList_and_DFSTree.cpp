#include <iostream>
#include <stack>
using namespace std;

typedef struct Node_t Node_t;
typedef struct Node_t* Node;

struct Node_t {
    int data;
    Node next;
};

Node newNode(int data, Node next) {
    Node node = new Node_t;
    node->data = data;
    node->next = next;
    return node;
}

// Function to add an edge to the graph
void addEdge(Node adj[], int u, int v) {
    adj[u] = newNode(v, adj[u]);
    adj[v] = newNode(u, adj[v]); // if you want to create directed graph, then comment out this line
}

// Function to print the graph
void printGraph(Node adj[], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << ": ";
        Node neighbor = adj[v];
        while (neighbor) {
            cout << neighbor->data << " ";
            neighbor = neighbor->next;
        }
        cout << endl;
    }
}


void DFS(Node adj[], int startingVertex, int V)
{
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

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
            for (Node neighbor = adj[v]; neighbor != NULL; neighbor = neighbor->next)
            {
                int vertex = neighbor->data;
                if (!visited[vertex])
                {
                    parent[vertex] = v;
                    stack.push(vertex);
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

    Node adj[V];
    for (int i = 0; i < V; ++i) {
        adj[i] = NULL; // Initialize each adjacency list as empty
    }

    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    cout << "Graph representation:" << endl;
    printGraph(adj, V);
    cout<<endl;
    
    int startingVertex;
    cout << "Enter the vertex from where to start the DFS Traversal: ";
    cin >> startingVertex;
    cout<<endl;

    DFS(adj, startingVertex, V);
    return 0;
}