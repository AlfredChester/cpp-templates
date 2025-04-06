#ifndef AFDS_SLIDING_WINDOW
#define AFDS_SLIDING_WINDOW

#include <functional>
#include <queue>
#include <vector>

template <class T, class Compare = std::less<T>> // by default, we find minimum.
std::vector<T> sliding_window(
    std::vector<T> A, size_t k, Compare comp = Compare()
) {
    std::vector<T> res;
    std::deque<size_t> Q;
    for (size_t i = 0; i < A.size(); i++) {
        if (!Q.empty() && Q[0] + k == i) {
            Q.pop_front();
        }
        while (!Q.empty() && comp(A[i], A[Q.back()])) {
            Q.pop_back();
        }
        Q.push_back(i);
        if (i + 1 >= k) { // warning: assert k >= 1
            res.push_back(A[Q[0]]);
        }
    }
    return res;
}
template <class T, class Compare = std::less<T>> // by default, we find minimum.
std::vector<std::vector<T>> grid_sliding_window(
    std::vector<std::vector<T>> &A,
    size_t x, size_t y, Compare comp = Compare()
) {
    const size_t n = A.size(), m = A[0].size();
    std::vector<std::vector<T>> cols(m - y + 1);
    std::vector<std::vector<T>> ans(n - x + 1, std::vector<T>(m - y + 1));
    for (size_t i = 0; i < n; i++) {
        std::vector<T> res = sliding_window(A[i], y, comp);
        for (size_t j = 0; j <= m - y; j++) {
            cols[j].push_back(res[j]);
        }
    }
    for (size_t j = 0; j <= m - y; j++) {
        std::vector<T> res = sliding_window(cols[j], x, comp);
        for (size_t i = 0; i <= n - x; i++) {
            ans[i][j] = res[i];
        }
    }
    return ans;
}

#endif // AFDS_SLIDING_WINDOW
