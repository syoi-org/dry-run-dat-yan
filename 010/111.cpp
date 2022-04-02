#include <bits/stdc++.h>
using namespace std;

// CF 913A - Modular Exponentiation
int main() {
    int n = 4, m = 42;
    if(n > 30)
        cout << m;
    else{
        int x = 1;
        for(int i=1;i<n;i++) x = x * 2 + 1;
        cout << (m & x);
    }
    return 0;
}
