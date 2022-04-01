#include <bits/stdc++.h>
using namespace std;

// CF 1195D1 - Submarine in the Rybinsk Sea (easy edition)
int main() {
	int n = 5;
	vector<string> v{"957", "235", "130", "202", "764"};
	const int M = 10;
	vector<vector<string>> b(M + 1);
	for (string s : v) b[s.size()].push_back(s);
 
	int ans = 0;
	for (int j=1;j<=M;j++) {
		for (string aj : b[j]) {
			for (int k=1;k<=M;k++) {
				int cmn = min(j, k);
				// contribution to left sum
				string strl;
				for (int i=0;i<cmn;i++) {
					strl = string{} + aj[j - i - 1] + strl;
					strl = string{} + '0' + strl;
				}
				strl = aj.substr(0, j - cmn) + strl;
				// cerr << strl << endl;
				ans += stoi(strl) * b[k].size();
				// contribution to right sum
				string strr;
				for (int i=0;i<cmn;i++) {
					strr = string{} + '0' + strr;
					strr = string{} + aj[j - i - 1] + strr;
				}
				strr = aj.substr(0, j - cmn) + strr;
				// cerr << strr << endl;
				ans += stoi(strr) * b[k].size();
			}
		}
	}
	cout << ans;
	return 0;
}