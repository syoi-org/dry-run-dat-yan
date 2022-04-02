#include <bits/stdc++.h>
using namespace std;

int main() {
    const char (*hello)[6] = &"hello";
    hello++;
    cout << *hello;
    return 0;
}
