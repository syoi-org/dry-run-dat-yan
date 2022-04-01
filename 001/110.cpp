#include <bits/stdc++.h>
using namespace std;

void f(int);
void g(int);

void f(int x) {
    if (x <= 1) {
        cout << "fWins";
    } else {
        g((x + 1) / 2);
    }
}

void g(int x) {
    if (x <= 1) {
        cout << "gWins";
    } else {
        f((x + 1) / 2);
    }
}

int main() {
    f(3);
    g(5);
    f(6);
    return 0;
}
