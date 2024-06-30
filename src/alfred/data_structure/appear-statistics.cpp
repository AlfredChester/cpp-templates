#include <bits/stdc++.h>

template <class _Tp>
struct Mess {
    std::vector<_Tp> v;
    bool initialized = false;
    inline _Tp origin(int idx) { return v[idx - 1]; }
    inline void insert(_Tp x) { v.push_back(x); }
    template <typename T, typename... V>
    inline void insert(T x, V... v) { insert(x), insert(v...); }
    inline void init(void) {
        sort(v.begin(), v.end()), initialized = true;
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    inline int query(_Tp x) {
        if (!initialized) init();
        return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    }
    inline bool exist(_Tp x) { return origin(query(x)) == x; }
};

template <class T>
class AppearStats { // Appear Statistics.
private:
    Mess<T> M;
    size_t n;
    std::vector<std::vector<int>> pos;

public:
    AppearStats(void) : n(0) {}
    AppearStats(std::vector<T> &init) : n(init.size()) { _init(init); }
    inline void _init(std::vector<T> &init) {
        for (auto item : init) M.insert(item);
        n = init.size(), M.init(), pos.resize(M.v.size());
        for (size_t i = 0; i < n; i++) {
            pos[M.query(init[i]) - 1].push_back(i);
        }
    }
    // Use「base」as the beginning of index, return -1 if x doesn't exist.
    inline int first(int l, int r, T x, int base = 0) {
        l -= base, r -= base;
        if (!M.exist(x)) return -1;
        std::vector<int> &P = pos[M.query(x) - 1];
        auto it = std::lower_bound(P.begin(), P.end(), l);
        return it == P.end() || *it > r ? -1 : *it + base;
    }
    // Use「base」as the beginning of index, return -1 if x doesn't exist.
    inline int last(int l, int r, T x, int base = 0) {
        l -= base, r -= base;
        if (!M.exist(x)) return -1;
        std::vector<int> &P = pos[M.query(x) - 1];
        auto it = std::upper_bound(P.begin(), P.end(), r);
        return it == P.begin() || *std::prev(it) < l ? -1 : *std::prev(it) + base;
    }
    inline int count(int l, int r, T x, int base = 0) {
        l -= base, r -= base;
        if (!M.exist(x)) return 0;
        std::vector<int> &P = pos[M.query(x) - 1];
        auto L = std::lower_bound(P.begin(), P.end(), l);
        auto R = std::upper_bound(P.begin(), P.end(), r);
        if (L == P.end() || R == P.begin()) return 0;
        if (*L > r || *std::prev(R) < l) return 0;
        return R - L;
    }
};