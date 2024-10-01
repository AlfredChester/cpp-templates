#include <bits/stdc++.h>

template <class T> // default max.
std::vector<T> sliding_window(std::vector<T> A, size_t k) {
    std::vector<T> res;
    std::deque<size_t> Q;
    for (size_t i = 0; i < A.size(); i++) {
        if (!Q.empty() && Q[0] + k == i) {
            Q.pop_front();
        }
        while (!Q.empty() && A[Q.back()] <= A[i]) {
            Q.pop_back();
        }
        Q.push_back(i);
        if (i >= k - 1) { // warning: assert k >= 1
            res.push_back(A[Q[0]]);
        }
    }
    return res;
}
template <class T>
std::vector<std::vector<T>> grid_sliding_window(
    std::vector<std::vector<T>> &A, size_t x, size_t y
) {
    const size_t n = A.size(), m = A[0].size();
    std::vector<std::vector<T>> cols(m - y + 1);
    std::vector<std::vector<T>> ans(n - x + 1, std::vector<T>(m - y + 1));
    for (size_t i = 0; i < n; i++) {
        std::vector<T> res = sliding_window(A[i], y);
        for (size_t j = 0; j <= m - y; j++) {
            cols[j].push_back(res[j]);
        }
    }
    for (size_t j = 0; j <= m - y; j++) {
        std::vector<T> res = sliding_window(cols[j], x);
        for (size_t i = 0; i <= n - x; i++) {
            ans[i][j] = res[i];
        }
    }
    return ans;
}