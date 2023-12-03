#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int minTime = 0;
        for (int i = 1; i < points.size(); ++i) {
            int xDiff = abs(points[i][0] - points[i - 1][0]);
            int yDiff = abs(points[i][1] - points[i - 1][1]);
            minTime += max(xDiff, yDiff); //Chebyshev distance (max of xDiff and yDiff)
                                          //is the minimum time to travel between two points 
                                          //as the grid has a uniform cost of 1
                                          //also
                                          //eulerian distance (sqrt(xDiff^2 + yDiff^2))
                                          //manhattan distance (xDiff + yDiff)
        }
        return minTime;
        
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<vector<int>> points = {{1, 1}, {3, 4}, {-1, 0}};
    int result = solution.minTimeToVisitAllPoints(points);

    cout << "Minimum time to visit all points: " << result << endl;

    return 0;
}