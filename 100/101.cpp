#include <bits/stdc++.h>
using namespace std;

// you guys hate pointers?
// okay. no pointers for this one
int h(int &x, int &y) {
    return y ^= x;
}

int g(int &x, int y) {
    x += h(y, x);
    return y = h(x, y);
}

int &f(int x, int &y) {
    return y += g(y, x);
}

int main() {
    int x = 2, y = 4;
    cout << f(x, y)++;
    return 0;
}