#include <iostream>
#include <queue>
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
    adj[v] = newNode(u, adj[v]);
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

void BFS(Node adj[], int s, int V)
{
    // Mark all the vertices as not visited
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

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
        for (Node neighbor = adj[s]; neighbor != NULL; neighbor = neighbor->next)
        {
            int adjacent = neighbor->data;
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push(adjacent);
            }
        }
    }
}

int main(int argc, char const* argv[]) {
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

    int startingVertex;
    cout << "Enter the vertex from where to start the BFS Traversal: ";
    cin >> startingVertex;
    cout << "Following is Breadth First Traversal (starting from vertex " << startingVertex << ") \n";

    BFS(adj, startingVertex, V);

    return 0;
}