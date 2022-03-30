#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 10; i; i -= (i + 1) / 2) cout << i;
    return 0;
}
