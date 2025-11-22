#ifndef AFDS_CARTESIAN
#define AFDS_CARTESIAN

#include <utility>
#include <vector>

// Returns pairs of (rt, vec(ls, rs)).
template <class T, class Comp = std::less<T>>
std::pair<int, std::vector<std::pair<int, int>>>
cartesian(std::vector<T> a, Comp comp = Comp()) {
    std::vector<int> stk; // stack of right chain.
    std::vector<std::pair<int, int>> ans;
    ans.assign(a.size(), std::make_pair(-1, -1));
    for (size_t i = 0; i < a.size(); i++) {
        int lst = -1;
        while (!stk.empty() && comp(a[i], a[stk.back()])) {
            lst = stk.back(), stk.pop_back();
        }
        if (!stk.empty()) ans[stk.back()].second = i;
        ans[i].first = lst, stk.push_back(i);
    }
    return std::make_pair(stk[0], ans);
}

#endif
