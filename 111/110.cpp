#include <bits/stdc++.h>
using namespace std;

// don't waste time checking my segment tree template
// i battle tested it with lots of contests
namespace Combine {
    template <class T> struct Sum {
        constexpr T operator()(const T &lhs, const T &rhs) { return lhs + rhs; }
        constexpr const T def() { return T(); }
    };
}

namespace Update {
    template <class T, class U = T, bool summation = false> struct Assign {
        constexpr T &operator()(T &lhs, const U &rhs, int len = 1) { return summation ? lhs = rhs * len : lhs = rhs; }
        constexpr U &upLazy(U &lhs, const U &rhs) { return lhs = rhs; }
        constexpr const U udef() { return U(); }
    };
}

template <class T, class U = T, class Combinator = Combine::Sum<T>, class Updater = Update::Assign<T>, class SegIndex = int>
class DynamicSegmentTree {
private:

    struct SegNode;

    // intentionally not using unique_ptr
    // unique_ptr is so 9 slow!
    // JUST LET IT LEAKKKKK
    using SegPointer = SegNode *;

    struct SegNode {
        T tree;
        U lazy;
        SegPointer lchi, rchi;
    };

    static inline Combinator combinator;
    static inline Updater updater;
    SegIndex n;
    SegPointer root = nullptr;
    const T defVal;

    void refreshNode(SegPointer &u, SegIndex lo, SegIndex hi) {
        if (u) return;
        u = SegPointer{new SegNode{defVal, updater.udef(), nullptr, nullptr}};
    }

    void apply(const U &val, SegPointer &u, SegIndex lo, SegIndex hi) {
        refreshNode(u, lo, hi);
        updater(u->tree, val, hi - lo + 1);
        updater.upLazy(u->lazy, val);
    }

    void push(SegPointer &u, SegIndex lo, SegIndex hi) {
        if (u->lazy != updater.udef()) {
            SegIndex mi = lo + (hi - lo) / 2;
            apply(u->lazy, u->lchi, lo, mi);
            apply(u->lazy, u->rchi, mi + 1, hi);
            u->lazy = updater.udef();
        }
    }

    void build(SegPointer &u, SegIndex lo, SegIndex hi, const std::vector<T> &init) {
        refreshNode(u, lo, hi);
        if (lo == hi) {
            u->tree = init[lo];
        } else {
            SegIndex mi = lo + (hi - lo) / 2;
            build(u->lchi, lo, mi, init);
            build(u->rchi, mi + 1, hi, init);
            u->tree = combinator(u->lchi->tree, u->rchi->tree);
        }
    }

    void modify(SegIndex l, SegIndex r, const U &val, SegPointer &u, SegIndex lo, SegIndex hi) {
        refreshNode(u, lo, hi);
        if (r < lo || l > hi || l > r) return;
        if (l <= lo && hi <= r) {
            apply(val, u, lo, hi);
            return;
        }
        push(u, lo, hi);
        SegIndex mi = lo + (hi - lo) / 2;
        modify(l, r, val, u->lchi, lo, mi);
        modify(l, r, val, u->rchi, mi + 1, hi);
        u->tree = combinator(u->lchi->tree, u->rchi->tree);
    }

    T query(SegIndex l, SegIndex r, SegPointer &u, SegIndex lo, SegIndex hi) {
        refreshNode(u, lo, hi);
        if (r < lo || l > hi || l > r) return combinator.def();
        if (l <= lo && hi <= r) {
            return u->tree;
        }
        push(u, lo, hi);
        SegIndex mi = lo + (hi - lo) / 2;
        T &&lres = query(l, r, u->lchi, lo, mi);
        T &&rres = query(l, r, u->rchi, mi + 1, hi);
        return combinator(lres, rres);
    }

public:
    explicit DynamicSegmentTree(const vector<T> &init) : n(init.size()), defVal(T()) {
        build(root, 0, n - 1, init);
    }
    explicit DynamicSegmentTree(SegIndex n, const T &def = combinator.def()) : n(n), defVal(def) {}

    void modify(SegIndex l, SegIndex r, const U &val) {
        modify(l, r, val, root, 0, n - 1);
    }

    T query(SegIndex l, SegIndex r) {
        return query(l, r, root, 0, n - 1);
    }

};

int main() {
    // initialize array
    int n = 10; vector<int> a;
    a[0] = 2;
    a[1] = 3;
    a[2] = 4;
    for (int i = 3; i < n; i++) a[i] = a[i - 1] + a[i - 2] % n;

    // use dynamic segment tree without delete to make it memleak :D
    DynamicSegmentTree<int> st(a); // pass a as initial array
    st.modify(2, 5, 3);
    cout << st.query(3, 6);
    st.modify(3, 3, 2);
    cout << st.query(0, 8);
    cout << st.query(3, 7);

    // yesterday was April Fools. did Tommy lie?
    return 0;
}
