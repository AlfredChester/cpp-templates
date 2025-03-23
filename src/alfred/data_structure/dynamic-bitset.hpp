#ifndef AFDS_DYNAMIC_BITSET
#define AFDS_DYNAMIC_BITSET

#include <limits>
#include <numeric>
#include <vector>

// TODO: Implement resize and bitwise operators. Figure out how to mod.

class DynamicBitset {
private:
    using Word_t = unsigned long long;
    constexpr static int bw = sizeof(Word_t) * 8;
    constexpr static Word_t WORD_MAX = std::numeric_limits<Word_t>::max();
    size_t n, cnt;
    std::vector<Word_t> bits;

    inline int calc_len(void) {
        return (std::max<size_t>(n, bw) + bw - 1) / bw;
    }

public:
    DynamicBitset(size_t N) : n(N), bits(calc_len()) {}
    inline int size(void) { return n; }
    inline int count(void) { return cnt; }
    inline int test(size_t i) { return (bits[i / bw] >> (i % bw)) & 1; }
    inline void set(size_t i, bool val = true) {
        if (test(i) == val) return;
        bits[i / bw] ^= (1ULL << (i % bw));
        val ? cnt++ : cnt--;
    }
    inline void flip(size_t i) {
        bits[i / bw] ^= (1ULL << (i % bw));
        test(i) ? cnt-- : cnt++;
    }
    inline void reset(void) {
        std::fill(bits.begin(), bits.end(), 0);
        cnt = 0;
    }
    inline void clear(void) {
        bits.clear(), cnt = n = 0;
    }
    // find the previous val before i. returns -1 if not found.
    inline int pre(size_t i, bool contain = false, bool val = true) {
        Word_t cur = bits[i / bw];
        for (int j = (int)(i % bw) - (!contain); j >= 0; j--) {
            if ((cur >> j & 1) == val) {
                return i - (i % bw - j);
            }
        }
        for (int j = i / bw - 1; j >= 0; j--) {
            if (bits[j] == (val ? 0 : WORD_MAX)) continue;
            for (int k = bw - 1; k >= 0; k--) {
                if ((bits[j] >> k & 1) == val) {
                    return j * bw + k;
                }
            }
        }
        return -1;
    }
    inline int suf(size_t i, bool contain = false, bool val = true) {
        Word_t cur = bits[i / bw];
        for (int j = i % bw + (!contain); j < bw; j++) {
            if ((cur >> j & 1) == val) {
                return i + (j - i % bw);
            }
        }
        const int len = calc_len();
        for (int j = i / bw + 1; j < len; j++) {
            if (bits[j] == (val ? 0 : WORD_MAX)) continue;
            for (int k = 0; k < bw; k++) {
                if ((bits[j] >> k & 1) == val) {
                    return j * bw + k;
                }
            }
        }
        return -1;
    }
};

#endif // AFDS_DYNAMIC_BITSET
