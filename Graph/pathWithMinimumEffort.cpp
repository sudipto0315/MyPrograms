#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int MinimumEffort(vector<vector<int>> &heights)
{
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>>
        pq;

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int diff = it.first;
        int row = it.second.first;
        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
            return diff;

        for (int i = 0; i < 4; i++)
        {
            int newr = row + dr[i];
            int newc = col + dc[i];

            if (newr >= 0 && newc >= 0 && newr < n && newc < m)
            {
                int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                if (newEffort < dist[newr][newc])
                {
                    dist[newr][newc] = newEffort;
                    pq.push({newEffort, {newr, newc}});
                }
            }
        }
    }
    return 0; // if unreachable
}

int main()
{
    // Driver Code.
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> heights(n, vector<int>(m));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> heights[i][j];
        }
    }

    int ans = MinimumEffort(heights);

    cout << "Minimum effort required: " << ans << endl;

    return 0;
}
