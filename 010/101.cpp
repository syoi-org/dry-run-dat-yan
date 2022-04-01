#include <bits/stdc++.h>
using namespace std;

void helloFunction(int x) {
    cout << "HiInt";
}

void helloFunction(double x) {
    cout << "HiDouble";
}

void helloFunction(long long x) {
    cout << "HiLongLong";
}

void helloFunction(int &x) {
    cout << "HiVariable";
}

int main() {
    helloFunction(2);    
    return 0;
}
