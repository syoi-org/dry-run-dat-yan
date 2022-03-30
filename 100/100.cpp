#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<int> v;
    iota(v.rbegin(), v.rend(), 0);
    do {
        for (int i = 0; i < n; i++) cout << v[i];
    } while (next_permutation(v.begin(), v.end()));
    cout << "!";
    return 0;
}