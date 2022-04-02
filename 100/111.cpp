#include <bits/stdc++.h>
using namespace std;

// CF 1099C - Postcard
int main() {
    string s = "z*mt*o?mxh?g";
    int k = 11;
    int n = s.size();
    int realN = 0;
    for (int i=0;i<n;i++) {
        if (i + 1 < n && (s[i + 1] == '?' || s[i + 1] == '*')) { i++; continue; }
        realN++;
    }
    if (k < realN) return cout << "Impossible", 0;
    string ans;
    int need = k - realN;
    for (int i=0;i<n;i++) {
        if (i + 1 < n && s[i + 1] == '?') {
            if (need > 0) ans.push_back(s[i]), need--;
            i++;
        } else if (i + 1 < n && s[i + 1] == '*') {
            while (need > 0) ans.push_back(s[i]), need--;
            i++;
        } else {
            ans.push_back(s[i]);
        }
    }
    if (int(ans.size()) == k)
        cout << ans;
    else
        cout << "Impossible";
    return 0;
}