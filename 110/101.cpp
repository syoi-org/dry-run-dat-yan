#include <bits/stdc++.h>
using namespace std;

int f(int x, int &y) {
    return x = ++y;
}

int main() {
    int x = -1, y = 8;
    cout << f(y = 3, ++x = 6);
    cout << x << y;
    return 0;
}
