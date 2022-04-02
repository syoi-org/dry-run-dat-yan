#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

// CF 178B1 - Greedy Merchants
int main() {
    int n = 7, m = 8;
    vector<pair<int, int>> edges;
    edges.emplace_back(1, 2);
    edges.emplace_back(2, 3);
    edges.emplace_back(3, 4);
    edges.emplace_back(4, 5);
    edges.emplace_back(5, 6);
    edges.emplace_back(5, 7);
    edges.emplace_back(3, 5);
    edges.emplace_back(4, 7);
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        auto [u, v] = edges[i];
        u--, v--;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }
 
    // dfs find bridge
    vector<int> isBridge(m);
    vector<int> stTime(n, INF), fiTime(n, INF);
    vector<int> low(n);
    int timer = 0;
    function<void(int, int)> dfs = [&] (int u, int p) {
        stTime[u] = timer++;
        low[u] = stTime[u];
        for (auto pr : g[u]) {
            int &v = pr.first, &i = pr.second;
            if (v == p) continue;
            if (stTime[v] >= INF) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (stTime[u] < low[v]) {
                    isBridge[i] = true;
                }
            } else if (fiTime[v] >= INF) {
                low[u] = min(low[u], stTime[v]);
            }
        }
        fiTime[u] = timer;
    };
    dfs(0, -1);
 
    // condense graph and compute parent
    vector<int> c(n, -1);
    vector<int> p(1, -1);
    vector<int> d(1, 0);
    dfs = [&] (int u, int o) {
        for (auto pr : g[u]) {
            int &v = pr.first, &i = pr.second;
            if (c[v] == -1) {
                if (isBridge[i]) {
                    c[v] = p.size();
                    p.push_back(c[u]);
                    d.push_back(d[c[u]] + 1);
                } else {
                    c[v] = c[u];
                }
                dfs(v, u);
            }
        }
    };
    c[0] = 0;
    dfs(0, -1);
 
    // precompute binary lifting table
    int cn = p.size();
    int M = 20;
    vector<vector<int>> dp(M, vector<int>(cn, -1));
    dp[0] = p;
    for (int j = 1; j < M; j++) {
        for (int i = 0; i < cn; i++) if (dp[j - 1][i] != -1)
            dp[j][i] = dp[j - 1][dp[j - 1][i]];
    }
 
    // lca
    auto lca = [&] (int u, int v) {
        if (d[u] > d[v]) swap(u, v);
        for (int j = M - 1; j >= 0; j--) if (dp[j][v] != -1 && d[dp[j][v]] >= d[u])
            v = dp[j][v];
        if (u == v) return u;
        for (int j = M - 1; j >= 0; j--) if (dp[j][u] != dp[j][v])
            u = dp[j][u], v = dp[j][v];
        return dp[0][u];
    };
 
    // yay
    vector<pair<int, int>> q;
    q.emplace_back(1, 5);
    q.emplace_back(2, 4);
    q.emplace_back(2, 6);
    q.emplace_back(4, 7);
    for (auto [x, y] : q) {
        x = c[x - 1], y = c[y - 1];
        int z = lca(x, y);
        cout << d[x] + d[y] - d[z] - d[z];
    }
    return 0;
}