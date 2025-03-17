#ifndef AFDS_SPARSE_TABLE
#define AFDS_SPARSE_TABLE

#include <numeric>
#include <vector>

template <class T>
struct MaxInfo {
    T val;
    MaxInfo(void) { val = std::numeric_limits<T>::min(); }
    template <class InitT>
    MaxInfo(InitT x) { val = x; }
    MaxInfo operator+(MaxInfo &x) {
        return {std::max(val, x.val)};
    }
};
template <class T>
struct MinInfo {
    T val;
    MinInfo(void) { val = std::numeric_limits<T>::max(); }
    template <class InitT>
    MinInfo(InitT x) { val = x; }
    MinInfo operator+(MinInfo &x) {
        return {std::min(val, x.val)};
    }
};
template <class T>
struct GcdInfo {
    T val;
    GcdInfo(void) { val = T(); }
    template <class InitT>
    GcdInfo(InitT x) { val = x; }
    GcdInfo operator+(GcdInfo &x) {
#if __cplusplus >= 201703L
        return {std::gcd(x.val, val)};
#else
        return {__gcd(x.val, val)};
#endif
    }
};
template <class T>
class SparseTable {
private:
    int n;
    std::vector<std::vector<T>> ST;

public:
    SparseTable(void) {}
    SparseTable(int N) : n(N), ST(N, std::vector<T>(std::__lg(N) + 1)) {}
    template <class InitT>
    SparseTable(std::vector<InitT> &_init) : SparseTable(_init.size()) { init(_init, true); }
    template <class InitT>
    inline void init(std::vector<InitT> &_init, bool internal = false) {
        if (!internal) {
            n = _init.size();
            ST.assign(n, std::vector<T>(std::__lg(n) + 1));
        }
        for (int i = 0; i < n; i++) ST[i][0] = T(_init[i]);
        for (int i = 1; (1 << i) <= n; i++) {
            for (int j = 0; j + (1 << i) - 1 < n; j++) {
                ST[j][i] = ST[j][i - 1] + ST[j + (1 << (i - 1))][i - 1];
            }
        }
    }
    inline T query(int l, int r) { // 0 based
        if (l > r) return T();
        int w = std::__lg(r - l + 1);
        return ST[l][w] + ST[r - (1 << w) + 1][w];
    }
    inline T disjoint_query(int l, int r) {
        T ans = T();
        for (int i = l; i <= r; i += (1 << std::__lg(r - i + 1))) {
            ans = ans + ST[i][std::__lg(r - i + 1)];
        }
        return ans;
    }
};

#endif // AFDS_SPARSE_TABLE
