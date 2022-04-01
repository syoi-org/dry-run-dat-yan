#include <bits/stdc++.h>
using namespace std;

int helloFunction(int x, int y) {
    return heyFunction(x, heyFunction(y, x));
}

int heyFunction(int y, int z) {
    return (y + z) / 2;
}

int main() {
    cout << helloFunction(3, 4);
    return 0;
}
