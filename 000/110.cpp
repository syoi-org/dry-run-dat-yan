#include <bits/stdc++.h>
using namespace std;

// I like never never land more
void callMyName(int times) {
    if (times == 0)
        cout << "Collar!";
    else {
        cout << "Call!";
        callMyName(times - 1);
    }
}

int main() {
    callMyName(3);
    return 0;
}
