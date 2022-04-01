#include <bits/stdc++.h>
using namespace std;

// CF 1209C - Paint the Digits
int main() {
	int n = 12;
	string s = "040425524644";
	vector<int> a(n);
	for (int i = 0; i < n; i++) a[i] = s[i] - '0';
	// brute cutoff
	for (int co = 0; co <= 9; co++) {
		int mxNum1 = 0, mxNum2 = co;
		string ans;
		for (int i = 0; i < n; i++) {
			if (a[i] < mxNum1 && a[i] < mxNum2) {
				break;
			} else if (a[i] >= mxNum2) {
				mxNum2 = a[i];
				ans.push_back('2');
			} else if (a[i] >= mxNum1 && a[i] <= co) {
				mxNum1 = a[i];
				ans.push_back('1');
			} else {
				break;
			}
		}
		if (int(ans.size()) == n)
			return cout << ans, 0;
	}
	cout << '-';
    return 0;
}
