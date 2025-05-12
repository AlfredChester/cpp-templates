#ifndef AFDS_SUM
#define AFDS_SUM

#include <numeric>
#include <vector>

template <class T>
class Sum {
private:
    int n;
    std::vector<T> _pre, _suf;

public:
    Sum(void) : n(0) {}
    template <class InitT>
    Sum(std::vector<InitT> &_init) { init(_init); }
    template <class InitT>
    inline void init(std::vector<InitT> &_init) {
        if (_init.empty()) return;
        _pre.resize(n = _init.size()), _suf.resize(n);
        _pre[0] = _init[0], _suf[n - 1] = _init[n - 1];
        for (int i = 1; i < n; i++) {
            _pre[i] = _pre[i - 1] + _init[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            _suf[i] = _suf[i + 1] + _init[i];
        }
    }
    inline T query(int l, int r) {
        if (l > r) return T();
        return l == 0 ? _pre[r] : _pre[r] - _pre[l - 1];
    }
    inline const T pre(int x) {
        return x < 0 ? T() : _pre[x];
    }
    inline const T suf(int x) {
        return x >= n ? T() : _suf[x];
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
    GridSum(std::vector<std::vector<InitT>> &_init) { init(_init); }
    template <class InitT>
    inline void init(std::vector<std::vector<InitT>> &_init) {
        if (_init.empty()) return;
        n = _init.size(), m = _init[0].size();
        sum.assign(n, std::vector<T>(m)), sum[0][0] = _init[0][0];
        for (size_t i = 1; i < n; i++) {
            sum[i][0] = sum[i - 1][0] + _init[i][0];
        }
        for (size_t i = 1; i < m; i++) {
            sum[0][i] = sum[0][i - 1] + _init[0][i];
        }
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 1; j < m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + _init[i][j];
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

template <class T>
class SubsetSum {
private:
    int n;
    std::vector<T> sum;

public:
    SubsetSum(void) : n(0) {}
    template <class InitT>
    SubsetSum(std::vector<InitT> &_init)
        : n(_init.size()), sum(_init) { init(_init, true); }
    template <class InitT>
    inline void init(std::vector<InitT> &_init, bool internal = false) {
        if (!internal) {
            n = _init.size(), sum = _init;
        }
        for (int i = 0; (1 << i) <= n; i++) {
            for (int S = 0; S < n; S++) {
                if (S >> i & 1) sum[S] += sum[S ^ (1 << i)];
            }
        }
    }
    inline T query(int mask) { return sum[mask]; }
};

#endif // AFDS_SUM
