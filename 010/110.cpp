#include <bits/stdc++.h>
using namespace std;

// please rewrite this in dp
int isThisFibo(int n) {
    if (n <= 2)
        return n;
    else
        return isThisFibo(n - 1) + isThisFibo(n - 2);
}

int main() {
    cout << isThisFibo(8);    
    return 0;
}
