#ifndef AFDS_CARTESIAN
#define AFDS_CARTESIAN

#include <pair>
#include <vector>

// Returns pair of (ls, rs).
template <class T, class Comp = std::less<T>>
std::vector<std::pair<int, int>> cartesian(std::vector<T> a, Comp comp) {
    std::vector<int> stk; // stack of right chain.
    std::vector<std::pair<int, int>> ans(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        int lst = -1;
        while (!stk.empty() && comp(a[i], a[stk.back()])) {
            lst = stk.back(), stk.pop_back();
        }
        if (!stk.empty()) ans[stk.back()].second = i;
        if (lst != -1) ans[i].first = lst;
        stk.push_back(i);
    }
    return ans;
}

#endif
