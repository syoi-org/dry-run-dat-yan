#include <bits/stdc++.h>
using namespace std;

// we all love define!
#define FOR(i) for (int i = 0; i < 3; i++)
#define FRO(i) for (int i : {0, 2, 1})
#define ROF(i) for (int i = 2; i >= 0; i--)
#define OFR(i) for (int i : {1, 0, 2})

int main() {
    string s;
    FRO(h) FOR(i) OFR(j) FRO(k) ROF(l) {
        if (i == j && j == k && k == l) s = s + s;
        s.push_back('a' + h + i + j + k + l);
    }
    cout << s.size() << s.substr(s.size() - 5, 19);
    return 0;
}
