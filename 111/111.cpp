#include <bits/stdc++.h>
using namespace std;

// CF 1624E - Masha-forgetful
int main() {
    // misread this trash problem twice
 
	// int n, m; cin >> n >> m;
	// vector<string> t(n); cin >> t;
	// string s; cin >> s;
	// vector<int> dp2(m, -1), dp3(m, -1);
	// for (int i = 0; i < m; i++) {
	// 	if (i >= 1) {
	// 		for (int j = 0; j < n; j++) {
	// 			if (s[i] == t[j][i] && s[i - 1] == t[j][i - 1]) {
	// 				if (i == 1 || dp2[i - 2] != -1 || dp3[i - 2] != -1) {
	// 					dp2[i] = j;
	// 					break;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	if (i >= 2) {
	// 		for (int j = 0; j < n; j++) {
	// 			if (s[i] == t[j][i] && s[i - 1] == t[j][i - 1] && s[i - 2] == t[j][i - 2]) {
	// 				if (i == 2 || dp2[i - 3] != -1 || dp3[i - 3] != -1) {
	// 					dp3[i] = j;
	// 					break;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// cerr << dp2 << dp3;
	// vector<pair<int, int>> ans;
	// int u = m - 1;
	// while (u >= 1) {
	// 	if (dp3[u] != -1) {
	// 		ans.emplace_back(u - 2, u);
	// 		u -= 3;
	// 	} else if (dp2[u] != -1) {
	// 		ans.emplace_back(u - 1, u);
	// 		u -= 2;
	// 	} else {
	// 		cout << -1 << endl;
	// 		return 0;
	// 	}
	// }
	// cout << ans.size() << endl;
	// for (auto [u, v] : ans) {
	// 	cout << u + 1 << " " << v + 1 << '\n';
	// }
 
	// int n, m; cin >> n >> m;
	// vector<string> t(n); cin >> t;
	// string s; cin >> s;
	// vector<pair<pair<int, int>, int>> ans;
	// vector<int> okay(m);
	// for (int j = 0; j + 1 < m; j++) {
	// 	for (int i = 0; i < n; i++) {
	// 		if (s[j] == t[i][j] && s[j + 1] == t[i][j + 1]) {
	// 			okay[j] = okay[j + 1] = 1;
	// 			ans.emplace_back(pair<int, int>(j + 1, j + 2), i + 1);
	// 		}
	// 	}
	// }
	// cerr << okay;
	// for (int j = 0; j < m; j++) if (!okay[j]) {
	// 	cout << -1 << endl;
	// 	return 0;
	// }
	// cout << ans.size() << endl;
	// for (auto [uv, w] : ans) {
	// 	cout << uv << " " << w << '\n';
	// }
 
	int n = 8, m = 7;
	vector<string> t;
    t.push_back("3654396");
    t.push_back("9503553");
    t.push_back("2307308");
    t.push_back("2838482");
    t.push_back("2505294");
    t.push_back("1985526");
    t.push_back("3325707");
    t.push_back("4177793");
	string s = "3848035";
	if (m == 1) {
		cout << -1 << endl;
		return 0;
	}
	for (auto &ti : t) for (auto &c : ti) c -= '0';
	for (auto &c : s) c -= '0';
	const int M = 10;
	vector<vector<vector<int>>> c3(M, vector<vector<int>>(M, vector<int>(M, -1)));
	auto d3 = c3;
	vector<vector<int>> c2(M, vector<int>(M, -1));
	auto d2 = c2;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (j + 2 < m) c3[t[i][j]][t[i][j + 1]][t[i][j + 2]] = i, d3[t[i][j]][t[i][j + 1]][t[i][j + 2]] = j;
		if (j + 1 < m) c2[t[i][j]][t[i][j + 1]] = i, d2[t[i][j]][t[i][j + 1]] = j;
	}
    vector<pair<int, int>> dp2(m, {-1, -1}), dp3(m, {-1, -1});
	for (int i = 0; i < m; i++) {
		if (i >= 1 && (i == 1 || dp2[i - 2].first != -1 || dp3[i - 2].first != -1)) {
			if (c2[s[i - 1]][s[i]] != -1)
				dp2[i] = {c2[s[i - 1]][s[i]], d2[s[i - 1]][s[i]]};
		}
		if (i >= 2 && (i == 2 || dp2[i - 3].first != -1 || dp3[i - 3].first != -1)) {
			if (c3[s[i - 2]][s[i - 1]][s[i]] != -1)
				dp3[i] = {c3[s[i - 2]][s[i - 1]][s[i]], d3[s[i - 2]][s[i - 1]][s[i]]};
		}
	}
	vector<pair<pair<int, int>, int>> ans;
	int u = m - 1;
	while (u >= 1) {
		if (dp3[u].first != -1) {
			ans.emplace_back(pair<int, int>{dp3[u].second + 1, dp3[u].second + 3}, dp3[u].first + 1);
			u -= 3;
		} else if (dp2[u].first != -1) {
			ans.emplace_back(pair<int, int>{dp2[u].second + 1, dp2[u].second + 2}, dp2[u].first + 1);
			u -= 2;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << ":";
	for (auto [uv, w] : ans) {
		cout << uv.first << "," << uv.second << "," << w << ';';
	}
    return 0;
}