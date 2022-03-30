#include <bits/stdc++.h>
using namespace std;

int main() {
    int b = 23, p = 17;
    vector<int> v{5};
    for (int i = 0; i < 6; i++) {
        v.push_back((v.back() * b + i) % p);
    }
    for (int &x : v) x &= 1;
    while (!v.empty()) {
        if (v.size() >= 2) {
            int x = v.back(); v.pop_back();
            int y = v.back(); v.pop_back();
            cout << x << y;
            if (x + y == 2) {
                v.push_back((v.size() * b % p) & 1);
            } else if (x + y == 1) {
                v.push_back(y);
            } else {
                v.push_back(x);
            }
        } else {
            cout << v.back();
            v.pop_back();
        }
    }
    return 0;
}