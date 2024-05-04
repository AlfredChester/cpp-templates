using i64 = long long;
using i128 = __int128;
class HashedString {
private:
    // change M and B if you want
    static const i64 M = (1LL << 61) - 1;
    static const i64 B;
    // pow[i] contains B^i % M
    static std::vector<i64> pow;
    // p_hash[i] is the hash of the first i characters of the given string
    std::vector<i64> r_hash, p_hash;
    i128 mul(i64 a, i64 b) { return (i128)a * b; }
    i64 mod_mul(i64 a, i64 b) { return mul(a, b) % M; }

public:
    HashedString(const string &s) : r_hash(s.size() + 1), p_hash(s.size() + 1) {
        while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
        p_hash[0] = 0;
        r_hash[0] = 0;
        for (size_t i = 0; i < s.size(); i++) {
            p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M; // 1-based
        }
        i64 sz = s.size();
        for (int i = sz - 1, j = 0; i >= 0; i--, j++) {
            r_hash[j + 1] = (mul(r_hash[j], B) + s[i]) % M;
        }
    }
    i64 getHash(int start, int end) { // 0 based
        i64 raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
        return (raw_val + M) % M;
    }
    i64 getRHash(int start, int end) { // 0 based
        i64 raw_val = r_hash[end + 1] - mod_mul(r_hash[start], pow[end - start + 1]);
        return (raw_val + M) % M;
    }
};
std::vector<i64> HashedString::pow = {1};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const i64 HashedString::B = uniform_int_distribution<i64>(0, M - 1)(rng);