#include <bits/stdc++.h>

template <class T>
class Sum {
private:
    size_t n;
    std::vector<T> sum;

public:
    Sum(void) : n(0) {}
    template <class InitT>
    Sum(std::vector<InitT> &init) { _init(init); }
    template <class InitT>
    inline void _init(std::vector<InitT> &init) {
        if (init.empty()) return;
        sum.resize(n = init.size()), sum[0] = init[0];
        for (size_t i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + init[i];
        }
    }
    inline T query(int l, int r) {
        if (l > r) return T();
        return l == 0 ? sum[r] : sum[r] - sum[l - 1];
    }
};
template <class T>
class GridSum {
private:
    size_t n, m;
    std::vector<std::vector<T>> sum;

public:
    GridSum(void) : n(0), m(0) {}
    template <class InitT>
    GridSum(std::vector<std::vector<InitT>> &init) { _init(init); }
    template <class InitT>
    inline void _init(std::vector<std::vector<InitT>> &init) {
        if (init.empty()) return;
        n = init.size(), m = init[0].size();
        sum.assign(n, std::vector<T>(m)), sum[0][0] = init[0][0];
        for (size_t i = 1; i < n; i++) {
            sum[i][0] = sum[i - 1][0] + init[i][0];
        }
        for (size_t i = 1; i < m; i++) {
            sum[0][i] = sum[0][i - 1] + init[0][i];
        }
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 1; j < m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + init[i][j];
            }
        }
    }
    inline T query(int x1, int y1, int x2, int y2) {
        T s1 = x1 == 0 ? 0 : sum[x1 - 1][y2];
        T s2 = y1 == 0 ? 0 : sum[x2][y1 - 1];
        T s3 = x1 == 0 || y1 == 0 ? 0 : sum[x1 - 1][y1 - 1];
        return sum[x2][y2] - s1 - s2 + s3;
    }
};