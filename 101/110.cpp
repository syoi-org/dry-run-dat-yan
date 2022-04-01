#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

// is it main?
int main() {
    auto main2 = main;
    cout << "x" << cnt++;
    if (cnt >= 5) return 0;
    main();
    cout << "y" << ++cnt;
    main2();
    cout << main();
    return 0;
}
