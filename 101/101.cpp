#include <bits/stdc++.h>
using namespace std;

// should constructors be considered as functions?
// btw, those guys below are conversion constructors
struct Bar {
	Bar(double j) { cout << "Bar"; }
};

struct Foo {
	Foo(Bar b) { cout << "Foo"; }
};

void fun(Foo f) { cout << "Fun"; }

int main() {
	fun(5);
    cout << "Main";
	return 0;
}
