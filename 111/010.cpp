#include <bits/stdc++.h>
using namespace std;

struct Compile {
    int *const * *const *const * compile = nullptr;
    int const *const *const *const *const *const * error = &compile;
    void ERROR() {
        const int *error = new int{4};
        reinterpret_cast<const void *&>(Compile::Compile::Compile::Compile::compile) = &error;
        delete *(Compile::error);
    }
};

int main() {
    Compile Compile;
    Compile.ERROR();
    cout << "COMPILE.Error()?";
    return 0;
}
