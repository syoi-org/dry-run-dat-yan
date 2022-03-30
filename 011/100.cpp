#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<vector<int>> g(n);
    g[0] = vector<int>{1, 2};
    g[1] = vector<int>{3, 2};
    g[3] = vector<int>{0, 1, 2};
    vector<int> visited(n);
    function<void(int)> dfs = [&] (int u) {
        visited[u] = 1;
        // lazy, next time sin code la
    }; 
    dfs(0);
    for (auto it = visited.rbegin(); it != visited.rend(); it++) cout << *it;
    return 0;
}