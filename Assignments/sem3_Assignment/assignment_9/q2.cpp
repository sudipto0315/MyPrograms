// #include <iostream>
// #include <vector>
// #include <queue>
// using namespace std;

// void addEdge(vector<vector<int>> &adj, int u, int v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u); // if you want to create a directed graph, then comment out this line
// }

// // Function to print the graph
// void printGraph(const vector<vector<int>> &adj)
// {
//     int V = adj.size();
//     for (int v = 0; v < V; ++v)
//     {
//         cout << "Adjacency list of vertex " << v << ": ";
//         for (int neighbor : adj[v])
//         {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }
// }

// void BFS(const vector<vector<int>> &adj, int s, int V)
// {
//     // Mark all the vertices as not visited
//     vector<bool> visited(V, false);
//     vector<int> distance(V, -1); // Initialize distances as -1 (unreachable)

//     // Create a queue for BFS using std::queue
//     queue<int> queue;

//     // Mark the current node as visited, set its distance to 0, and enqueue it
//     visited[s] = true;
//     distance[s] = 0;
//     queue.push(s);

//     while (!queue.empty())
//     {
//         // Dequeue a vertex from the queue and print it
//         s = queue.front();
//         cout << "Vertex " << s << " is at distance " << distance[s] << endl;
//         queue.pop();

//         // Get all adjacent vertices of the dequeued vertex s.
//         // If an adjacent has not been visited, then mark it visited, set its distance, and enqueue it
//         for (auto adjacent : adj[s])
//         {
//             if (!visited[adjacent])
//             {
//                 visited[adjacent] = true;
//                 distance[adjacent] = distance[s] + 1;
//                 queue.push(adjacent);
//             }
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int V;
//     cout << "Enter the number of vertices: ";
//     cin >> V;

//     vector<vector<int>> adj(V);

//     int E;
//     cout << "Enter the number of edges: ";
//     cin >> E;

//     cout << "Enter the edges (vertex pairs):" << endl;
//     for (int i = 0; i < E; ++i)
//     {
//         int u, v;
//         cin >> u >> v;
//         addEdge(adj, u, v);
//     }

//     cout << "Graph representation:" << endl;
//     printGraph(adj);

//     int startingVertex;
//     cout << "Enter the vertex from where to start the BFS Traversal: ";
//     cin >> startingVertex;

//     cout << "BFS Traversal and Shortest Distances:" << endl;
//     BFS(adj, startingVertex, V);

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

pair<int, int> bfsFarthestVertex(const vector<vector<int>> &adj, int start) {
    vector<int> distance(adj.size(), -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    int farthestVertex = start;
    int maxDistance = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
                if (distance[v] > maxDistance) {
                    maxDistance = distance[v];
                    farthestVertex = v;
                }
            }
        }
    }

    return make_pair(farthestVertex, maxDistance);
}

int findDiameter(const vector<vector<int>> &adj) {
    // Find the farthest vertex from an arbitrary starting point
    pair<int, int> result1 = bfsFarthestVertex(adj, 0);

    // Find the farthest vertex from the previously found farthest vertex
    pair<int, int> result2 = bfsFarthestVertex(adj, result1.first);

    return result2.second;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);
    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int diameter = findDiameter(adj);
    cout << "The diameter of the graph is: " << diameter << endl;

    return 0;
}
