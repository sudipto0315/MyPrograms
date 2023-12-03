#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

long long sumOfMultiples(int n, int k) {
    long long m = (n - 1) / k; // number of multiples of k less than n
    return k * m * (m + 1) / 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = sumOfMultiples(n, 3) + sumOfMultiples(n, 5) - sumOfMultiples(n, 15);
        cout << sum << endl;
    }
    return 0;
}