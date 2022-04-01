#include <bits/stdc++.h>
using namespace std;

// I just copied this from one of my exam questions
// Do you like it?
template <typename T>
class A {
public:
    T funcWithSyntaxError() {
        int a = 10;
        int* p = a; // This line has syntax error
        return a;
    }
};

int main() {
    A<int> obj;
    cout << "OppsForgotFuncCall";
    return 0;
}