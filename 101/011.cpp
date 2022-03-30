#include <bits/stdc++.h>
using namespace std;

using uc = unsigned char;

int main() {
    // char is only 8 bit, just brute it!
    for (uc i = ~uc(0); true; i--) {
        if (i % 5 == 2 && i % 4 == 3 && i % 11 == 5) {
            cout << int(i);
            break;
        }
    }
    return 0;
}
