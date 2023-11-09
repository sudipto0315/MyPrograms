#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the sum of weights of edges of the Minimum Spanning Tree.
int findMST(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    // {wt, node}
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (vis[node] == 1)
            continue;
        // add it to the MST
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edW = it[1];
            if (!vis[adjNode])
            {
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj[V];
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cout << "Enter edge (u v weight): ";
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int sum = findMST(V, adj);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << sum << endl;

    return 0;
}
