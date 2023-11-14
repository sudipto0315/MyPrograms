#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<pair<int, int>>> &adjList)
{
    priority_queue<pair<int, int>,
                   vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});

    int mod = static_cast<int>(1e9 + 7);

    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adjList[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});
                ways[adjNode] = ways[node];
            }
            else if (dis + edW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}

int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<pair<int, int>>> adjList(n);

    cout << "Enter the edges in the format (from to weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight});
    }

    int ans = countPaths(n, adjList);

    cout << "Number of ways to reach the destination: " << ans << endl;

    return 0;
}
