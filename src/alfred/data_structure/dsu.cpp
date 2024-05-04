struct DSU {
    std::vector<int> fa;
    DSU(int n) : fa(n + 1) {
        iota(fa.begin(), fa.end(), 0);
    }
    inline int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    inline void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
    }
};