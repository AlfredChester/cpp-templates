#ifndef AFDS_CANCEL_DSU
#define AFDS_CANCEL_DSU

#include <numeric>
#include <stack>
#include <vector>

class CancelDSU {
private:
    std::stack<int> S;
    std::vector<int> fa, siz;

public:
    CancelDSU(int n) : fa(n + 1), siz(n + 1, 1) {
        std::iota(fa.begin(), fa.end(), 0);
    }
    inline int find(int x) {
        return fa[x] == x ? x : find(fa[x]);
    }
    inline bool same(int x, int y) {
        return find(x) == find(y);
    }
    inline int size(int u) { return siz[find(u)]; }
    inline void merge(int u, int v) {
        int fu = find(u), fv = find(v);
        if (fu == fv) return S.push(-1);
        if (siz[fu] < siz[fv]) std::swap(fu, fv);
        siz[fu] += siz[fv], fa[fv] = fu, S.push(fv);
    }
    inline void _cancel(void) {
        if (S.empty()) return;
        if (S.top() == -1) return S.pop();
        siz[fa[S.top()]] -= siz[S.top()];
        fa[S.top()] = S.top(), S.pop();
    }
    inline void cancel(int t = 1) {
        while (t--) _cancel();
    }
};

#endif // AFDS_CANCEL_DSU
