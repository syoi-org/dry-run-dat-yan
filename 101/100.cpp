#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v{0, 2, 3, 1, 4};
    int n = v.size();
    for (int i = 0; i < n; i++) {
        swap(v[v[i]], v[v[v[i]]]);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i];
    }
    return 0;
}