#ifndef AFDS_CHTHOLLY
#define AFDS_CHTHOLLY

#include <set>

template <class T>
struct ChthollyTree {
    using i64 = long long;
    struct Node {
        mutable i64 l, r;
        mutable T v;
        bool operator<(const Node &x) const {
            return l < x.l;
        }
    };
    std::set<Node> tr;
    using iterator = typename std::set<Node>::iterator;
    ChthollyTree(void) = default;
    ChthollyTree(int rng, T val = T{}) { init(rng, val); }
    inline void init(i64 rng, T val = T{}) noexcept {
        tr.insert({0, rng, val}), tr.insert({rng + 1, rng + 1, 0});
    }
    inline iterator begin(void) const noexcept { return tr.begin(); }
    inline iterator end(void) const noexcept { return tr.end(); }
    inline iterator split(i64 pos) {
        auto it = tr.lower_bound({pos, 0, 0});
        if (it != tr.end() && it->l == pos) return it;
        i64 l = (--it)->l, r = it->r;
        const T v = it->v;
        tr.erase(it), tr.insert({l, pos - 1, v});
        return tr.insert({pos, r, v}).first;
    }
    inline void assign(i64 l, i64 r, T v) {
        auto R = split(r + 1), L = split(l);
        tr.erase(L, R), tr.insert({l, r, v});
    }
    template <class _Functor> // func(iterator)
    inline void modify(i64 l, i64 r, _Functor func) {
        auto R = split(r + 1), L = split(l);
        for (auto it = L; it != R; it++) func(it);
    }
    template <class _Functor> // func(T &, iterator)
    inline T query(i64 l, i64 r, _Functor func) {
        T ans{};
        auto R = split(r + 1);
        for (auto it = split(l); it != R; it++) func(ans, it);
        return ans;
    }
};

#endif // AFDS_CHTHOLLY
