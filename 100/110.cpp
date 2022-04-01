#include <bits/stdc++.h>
using namespace std;

void quickSort(int l, int r, vector<int> &v) {
    if (l == r) {
        return;
    }
    int pivot = l; // just choose left as pivot, hope not worst case la
    vector<int> lo, mi, hi;
    for (int i = l; i <= r; i++) {
        if (v[i] < v[pivot]) {
            lo.push_back(v[i]);
        } else if (v[i] > v[pivot]) {
            hi.push_back(v[i]);
        } else {
            mi.push_back(v[i]);
        }
    }
    int j = l;
    for (int x : lo) v[j++] = x;
    for (int x : mi) v[j++] = x;
    for (int x : hi) v[j++] = x;
    quickSort(l, l + lo.size() - 1, v);
    quickSort(r - hi.size() + 1, r, v);
}

int main() {
    vector<int> v{5, 1, 3, 2, 8, 6, 3, 2};
    quickSort(0, v.size() - 1, v);
    for (int i = 0; i < 8; i++) cout << v[i];
    return 0;
}
