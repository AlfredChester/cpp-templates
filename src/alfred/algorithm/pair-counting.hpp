#ifndef AFALG_PAIR_COUNTING
#define AFALG_PAIR_COUNTING

#include <algorithm>
#include <vector>

template <class T, class C>
inline size_t __count_pair(
    std::vector<T> &vec, size_t l, size_t r, C comp
) {
    if (r - l == 1) return 0;
    size_t ans = 0, m = (l + r) / 2;
    ans += __count_pair(vec, l, m, comp);
    ans += __count_pair(vec, m, r, comp);
    std::vector<T> tmp(r - l + 1);
    size_t it1 = l, it2 = m, it3 = 0;
    while (it1 < m && it2 < r) {
        if (comp(vec[it1], vec[it2])) {
            ans += r - it2, tmp[it3++] = vec[it1++];
        } else {
            tmp[it3++] = vec[it2++];
        }
    }
    while (it1 < m) tmp[it3++] = vec[it1++];
    while (it2 < r) tmp[it3++] = vec[it2++];
    for (size_t i = l; i < r; i++) {
        vec[i] = tmp[i - l];
    }
    return ans;
}

template <class T, class C>
inline size_t count_pair(std::vector<T> vec, C comp) {
    return __count_pair(vec, 0, vec.size(), comp);
}

#endif // AFALG_PAIR_COUNTING
