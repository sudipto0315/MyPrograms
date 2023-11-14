#include <bits/stdc++.h>
using namespace std;

int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stops > K)
            continue;

        for (auto iter : adj[node])
        {
            int adjNode = iter.first;
            int edW = iter.second;

            if (cost + edW < dist[adjNode] && stops <= K)
            {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}

int main()
{
    int n, src, dst, K;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the source, destination, and maximum stops (src dst K): ";
    cin >> src >> dst >> K;

    int numFlights;
    cout << "Enter the number of flights: ";
    cin >> numFlights;

    vector<vector<int>> flights(numFlights, vector<int>(3));
    cout << "Enter the flights (from to cost):" << endl;
    for (int i = 0; i < numFlights; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> flights[i][j];
        }
    }

    int ans = CheapestFLight(n, flights, src, dst, K);

    cout << "Minimum cost for the flight: " << ans << endl;

    return 0;
}
