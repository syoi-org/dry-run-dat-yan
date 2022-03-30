#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 9; i < 13; i++) for (int j = i; j <= i + j / 2; j += j * j) for (int r = j; r >= i; r--)
        cout << i - j + r;
    return 0;
}
