#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &g, vector<int> &res, vector<int> &inDeg, int u) {
    res.push_back(u);
    for (int v : g[u]) {
        inDeg[v]--;
        if (inDeg[v] == 0) {
            dfs(g, res, inDeg, v);
        }
    }
}

int main() {
    // graph in adj matrix representation
    vector<vector<int>> g(5);
    g[0] = {1, 2, 4};
    g[1] = {0, 3};
    g[2] = {3, 4};
    g[3] = {0, 1, 2};
    g[4] = {2};

    // topological sort
    vector<int> inDeg(5);
    for (int u = 0; u < 5; u++) for (int v : g[u]) inDeg[v]++;

    // i like dfs better, recursion is cool!    
    vector<int> res;
    for (int i = 0; i < 5; i++) {
        dfs(g, res, inDeg, i);
    }

    // cannot be top sorted if result does not consist of all nodes
    if (res.size() < 5) {
        cout << "Nope.";
    } else {
        for (int x : res) cout << x;
    }

    return 0;
}
