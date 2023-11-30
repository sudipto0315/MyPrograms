#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii; // {weight, vertex}

vector<int> dijkstra(vector<vector<pii>> &graph, int source, int V)
{
    int n = graph.size();
    vector<bool> visited(V, false);
    vector<int> Distance(n, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // {weight, vertex} min heap

    Distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
        {
            int v = i->first;
            int w = i->second;
            if (!visited[v] && Distance[u] + w < Distance[v])
            {
                Distance[v] = Distance[u] + w;
                pq.push({Distance[v], v});
            }
        }
    }

    return Distance;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<pii>> graph(n);
    cout << "Enter edges and weights:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int myLocation, friendLocation;
    cout << "Enter Your Location: ";
    cin >> myLocation;
    cout << "Enter Your Friend's Location: ";
    cin >> friendLocation;
    vector<int> myLocationVec = dijkstra(graph, myLocation, n);
    vector<int> friendLocationVec = dijkstra(graph, friendLocation, n);

    vector<int> equiDistanceNodes; // this vector will store the nodes which are at equal distance from both the friends

    for (int i = 0; i < min(myLocationVec.size(), friendLocationVec.size()); i++) // because if the graph is not connected then the size of the vector will be different
    {
        if (myLocationVec[i] == friendLocationVec[i])
        {
            equiDistanceNodes.push_back(i);
        }
    }

    sort(equiDistanceNodes.begin(), equiDistanceNodes.end());
    if (!equiDistanceNodes.empty())
        cout << "The node" << equiDistanceNodes[0] << " is the Equal Distance to both of them" << endl; // because the vector is sorted
    else
        cout << "No equidistance point exists!!" << endl;
    return 0;
}
