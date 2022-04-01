#include <bits/stdc++.h>
using namespace std;

template <typename S, typename T, int x>
int fun(S lhs, T rhs) { lhs = rhs; return x; }

class Foo {};
class Bar : public Foo {};

int main() {
	int (*first)(int, int) = fun<int, int, 8>;
	int (*second)(int *const, int[]) = &fun<int[], int *const, 5>;
	int (*third)(Foo, const Foo&) = fun<Foo, const Foo&, 3>;

	int arr[]{2, 3, 5};
	cout << (*first)(second(new int[5], arr), third(Bar{}, Bar{}));

	return 0;
}
