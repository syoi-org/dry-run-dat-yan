#include <bits/stdc++.h>
using namespace std;

int main() {
    // do you like Fenwick?
    for (int i = 51; i > 0; i -= i & -i) cout << i;
    return 0;
}
