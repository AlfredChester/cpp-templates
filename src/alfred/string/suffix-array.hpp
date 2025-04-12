#ifndef AFSTR_SUFFIX_ARRAY
#define AFSTR_SUFFIX_ARRAY

#include <algorithm>
#include <string>
#include <vector>

#include "../data_structure/info.hpp"
#include "../data_structure/sparse-table.hpp"

class SuffixArray {
private:
    int n;
    std::string s; // internal is 1-index, access is 0-indexed.
    SparseTable<MinInfo<int>> ST;
    std::vector<int> sa, rnk, old, h;

public:
    SuffixArray(std::string S) : n(S.size()), s(S) {
        const int m = n + 1;
        s.insert(s.begin(), ' '), sa.assign(m, 0);
        rnk.assign(m, 0), old.assign(m, 0), h.assign(m, 0);
        for (int i = 1; i <= n; i++) sa[i] = i, rnk[i] = s[i];

        for (int w = 1; w < n; w *= 2) {
            std::copy(rnk.begin(), rnk.end(), old.begin());
            auto cmp = [&](int x, int y) {
                if (old[x] != old[y]) return old[x] < old[y];
                if (y + w > n) return false;
                if (x + w > n) return true;
                return old[x + w] < old[y + w];
            };
            std::sort(std::next(sa.begin()), sa.end(), cmp);
            for (int i = 1; i <= n; i++) {
                rnk[sa[i]] = rnk[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
            }
            if (rnk[sa[n]] == n) break;
        }

        for (int i = 1, k = 0; i <= n; i++) {
            if (rnk[i] == 0) continue;
            if (k != 0) k--;
            while (std::max(i, sa[rnk[i] - 1]) <= n - k &&
                   s[i + k] == s[sa[rnk[i] - 1] + k]) {
                k++;
            }
            h[rnk[i]] = k;
        }
        ST.init(h);
    }
    const std::vector<int> get_h(void) { return h; }
    const std::vector<int> get_sa(void) { return sa; }
    const std::vector<int> get_rnk(void) { return rnk; }
    inline int lcp(int i, int j) { // 0-indexed !
        i = rnk[i + 1], j = rnk[j + 1];
        if (i > j) std::swap(i, j);
        return i == j ? n - i : ST.query(i + 1, j).val;
    }
};

#endif
