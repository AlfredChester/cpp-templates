#ifndef AFDS_SUM
#define AFDS_SUM

#include <vector>

template <class T>
class Sum {
private:
    int n;
    std::vector<T> _pre, _suf;

public:
    Sum(void) : n(0) {}
    template <class InitT>
    Sum(std::vector<InitT> &init) { _init(init); }
    template <class InitT>
    inline void _init(std::vector<InitT> &init) {
        if (init.empty()) return;
        _pre.resize(n = init.size()), _suf.resize(n);
        _pre[0] = init[0], _suf[n - 1] = init[n - 1];
        for (int i = 1; i < n; i++) {
            _pre[i] = _pre[i - 1] + init[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            _suf[i] = _suf[i + 1] + init[i];
        }
    }
    inline T query(int l, int r) {
        if (l > r) return T();
        return l == 0 ? _pre[r] : _pre[r] - _pre[l - 1];
    }
    inline const T pre(int x) { return _pre[x]; }
    inline const T suf(int x) { return _suf[x]; }
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

#endif // AFDS_SUM
