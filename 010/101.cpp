#include <bits/stdc++.h>
using namespace std;

int helloFunction(int x) {
    cout << "HiInt";
}

int helloFunction(double x) {
    cout << "HiDouble";
}

int helloFunction(long long x) {
    cout << "HiLongLong";
}

int helloFunction(int &x) {
    cout << "HiVariable";
}

int main() {
    cout << helloFunction(2);    
    return 0;
}
