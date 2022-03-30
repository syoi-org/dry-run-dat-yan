#include <bits/stdc++.h>
using namespace std;

void compile(char *error) {
    cout << "error?";
}

void compile(char error[]) {
    cout << "error!";
}

int main() {
    compile("error");
    return 0;
}