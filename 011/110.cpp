#include <bits/stdc++.h>
using namespace std;


int main() {
    string beauty = "baca";
    vector<int> used(4);
    string cur;
    function<void(int)> gen = [&] (int u) {
        if (u >= 2) {
            cout << cur;
        } else {
            for (int j = 0; j < 4; j++) if (!used[j]) {
                used[j] = 1;
                cur.push_back(beauty[j]);
                gen(u + 1);
                cur.pop_back();
                used[j] = 0;
            }
        }
    };
    gen(0);
    return 0;
}
