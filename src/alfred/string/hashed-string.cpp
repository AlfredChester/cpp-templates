template <int mod, int seed>
struct SingleHash {
    int n;
    std::vector<int> pow, h;
    SingleHash(void) = default;
    SingleHash(std::string &s) { init(s); }
    inline void init(std::string &s) {
        n = s.size(), h.assign(n + 2, 0), pow.assign(n + 2, 1);
        for (int i = 1; i <= n; i++) {
            pow[i] = 1ll * pow[i - 1] * seed % mod;
            h[i] = (1ll * h[i - 1] * seed + s[i - 1]) % mod;
        }
    }
    inline int get_hash(int l, int r) {
        return (h[r + 1] - 1ll * h[l] * pow[r - l + 1] % mod + mod) % mod;
    }
    inline bool check_same(int l1, int r1, int l2, int r2) {
        return get_hash(l1, r1) == get_hash(l2, r2);
    }
};
struct HashedString {
    SingleHash<998244353, 477> H1;
    SingleHash<1000000007, 233> H2;
    HashedString(void) = default;
    HashedString(std::string s) : H1(s), H2(s) {}
    inline void init(std::string s) {
        H1.init(s), H2.init(s);
    }
    std::pair<int, int> get_hash(int l, int r) { // not recommended.
        return {H1.get_hash(l, r), H2.get_hash(l, r)};
    }
    // caution: index begins with zero.
    // If index beginning with one is wanted, use s = ' ' + s
    inline bool check_same(int l1, int r1, int l2, int r2) {
        return H1.check_same(l1, r1, l2, r2) && H2.check_same(l1, r1, l2, r2);
    }
    inline bool check_period(int l, int r, int p) {
        return check_same(l, r - p, l + p, r);
    }
};
