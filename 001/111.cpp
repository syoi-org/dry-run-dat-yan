#include <bits/stdc++.h>
using namespace std;

// CF 155A - I_love_%username%
int main() {
    int n = 5;
	vector<int> a{100, 50, 200, 150, 200};
	int ans = 0, mn = a[0], mx = a[0];
	for(int i=1;i<n;i++){
		if(a[i] < mn || a[i] > mx) ans++;
		mn = min(a[i], mn);
		mx = max(a[i], mx);
	}		
	cout << ans;
    return 0;
}
