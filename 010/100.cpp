#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a{1, 2, 3};
    vector<int> b{2, 1, 3};
    if (a < b)
        cout << "Smaller";
    else
        cout << "NotSmaller";
    return 0;
}