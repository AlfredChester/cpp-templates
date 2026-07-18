#ifndef AFDS_DYNAMIC_BITSET
#define AFDS_DYNAMIC_BITSET

#include <climits>
#include <cstring>
#include <numeric>
#include <vector>

/**
 * DynamicBitset — a runtime-sized bitset with O(1) amortised set/test/flip,
 * O(N/W) next/prev scan, and an O(N/W) popcount cache.
 *
 * Word_t is unsigned long long (64 bits).  All bit indices are 0-based.
 */
class DynamicBitset {
public:
    using Word_t = unsigned long long;

private:
    static constexpr int  BW       = sizeof(Word_t) * CHAR_BIT; // 64
    static constexpr Word_t ONE    = Word_t(1);
    static constexpr Word_t ALLONE = ~Word_t(0);

    size_t              n_;    // logical size
    size_t              cnt_;  // popcount cache
    std::vector<Word_t> data_; // ceil(n / BW) words

    // Number of words needed for n_ bits.
    static constexpr size_t words_for(size_t n) {
        return (n + BW - 1) / BW;
    }

    // Mask for valid bits in the last word (always non-zero because we
    // always have at least 1 bit).
    Word_t last_mask() const {
        int rem = (int)(n_ % BW);
        return rem == 0 ? ALLONE : (ONE << rem) - ONE;
    }

public:
    // ----- Construction ------------------------------------------------

    explicit DynamicBitset(size_t n = 0)
        : n_(n), cnt_(0), data_(words_for(n), Word_t(0)) {}

    // Initialise from a string of '0'/'1' characters (index 0 = leftmost char).
    DynamicBitset(size_t n, const char* str)
        : n_(n), cnt_(0), data_(words_for(n), Word_t(0)) {
        for (size_t i = 0; i < n_; i++) {
            if (str[i] == '1') {
                data_[i / BW] |= ONE << (i % BW);
                cnt_++;
            }
        }
    }

    // ----- Basic accessors ---------------------------------------------

    size_t size()  const { return n_; }
    size_t count() const { return cnt_; }
    bool   none()  const { return cnt_ == 0; }
    bool   any()   const { return cnt_ != 0; }
    bool   all()   const { return cnt_ == n_; }

    // ----- Single-bit operations (O(1)) --------------------------------

    // Returns 1 if bit i is set, 0 otherwise.
    int test(size_t i) const {
        return (int)((data_[i / BW] >> (i % BW)) & ONE);
    }

    // Sets bit i to val (default true).
    void set(size_t i, bool val = true) {
        Word_t& w   = data_[i / BW];
        Word_t  bit = ONE << (i % BW);
        // Branchless: add val - old_bit to cnt_.
        int old = (int)((w >> (i % BW)) & ONE);
        w = val ? (w | bit) : (w & ~bit);
        cnt_ += (int)val - old;
    }

    // Resets (clears) bit i.
    void reset(size_t i) { set(i, false); }

    // Flips bit i.
    void flip(size_t i) {
        Word_t& w = data_[i / BW];
        Word_t  bit = ONE << (i % BW);
        w ^= bit;
        // If bit is now set, cnt_ increases; otherwise decreases.
        if (w & bit) cnt_++;
        else          cnt_--;
    }

    // ----- Bulk operations (O(N/W)) ------------------------------------

    // Sets all bits to 0.
    void reset() {
        std::fill(data_.begin(), data_.end(), Word_t(0));
        cnt_ = 0;
    }

    // Sets all bits to 1.
    void set() {
        std::fill(data_.begin(), data_.end(), ALLONE);
        // Zero out padding bits in the last word.
        if (!data_.empty()) data_.back() &= last_mask();
        cnt_ = n_;
    }

    // Flips all bits.
    void flip() {
        for (auto& w : data_) w ^= ALLONE;
        if (!data_.empty()) data_.back() &= last_mask();
        cnt_ = n_ - cnt_;
    }

    // Clears and resizes to 0.
    void clear() {
        data_.clear();
        n_ = cnt_ = 0;
    }

    // ----- Next / previous set (or unset) bit scan (O(N/W)) -----------

    /**
     * suf(i, contain, val)
     *   Returns the smallest index j >= i (or > i if !contain) such that
     *   test(j) == val.  Returns -1 if no such index exists in [0, n_).
     */
    int suf(size_t i, bool contain = false, bool val = true) const {
        size_t start = i + !contain; // first candidate
        if (start >= n_) return -1;

        size_t wi = start / BW;
        int    bi = (int)(start % BW);

        // Check the first (possibly partial) word.
        {
            Word_t w = val ? data_[wi] : ~data_[wi];
            // Mask off bits before 'bi'.
            w &= ALLONE << bi;
            if (w) {
                int pos = (int)(wi * BW) + __builtin_ctzll(w);
                return pos < (int)n_ ? pos : -1;
            }
            wi++;
        }

        // Scan remaining words.
        const size_t nw = data_.size();
        while (wi < nw) {
            Word_t w = val ? data_[wi] : ~data_[wi];
            if (w) {
                int pos = (int)(wi * BW) + __builtin_ctzll(w);
                return pos < (int)n_ ? pos : -1;
            }
            wi++;
        }
        return -1;
    }

    /**
     * pre(i, contain, val)
     *   Returns the largest index j <= i (or < i if !contain) such that
     *   test(j) == val.  Returns -1 if no such index exists in [0, n_).
     */
    int pre(size_t i, bool contain = false, bool val = true) const {
        if (i >= n_) i = n_ - 1; // clamp
        // 'end' is the inclusive upper bound we consider.
        size_t end = contain ? i : (i == 0 ? (size_t)-1 : i - 1);
        if (end >= n_) return -1; // underflow when i==0 && !contain

        size_t wi = end / BW;
        int    bi = (int)(end % BW);

        // Check the first (possibly partial) word.
        {
            Word_t w = val ? data_[wi] : ~data_[wi];
            // Mask off bits after 'bi'.
            // shift amount: BW - 1 - bi
            w &= ALLONE >> (BW - 1 - bi);
            if (w) {
                return (int)(wi * BW) + (BW - 1 - __builtin_clzll(w));
            }
            if (wi == 0) return -1;
            wi--;
        }

        // Scan remaining words downward.
        while (true) {
            Word_t w = val ? data_[wi] : ~data_[wi];
            if (w) {
                return (int)(wi * BW) + (BW - 1 - __builtin_clzll(w));
            }
            if (wi == 0) break;
            wi--;
        }
        return -1;
    }

    // ----- Bitwise operators (O(N/W)) ----------------------------------

    DynamicBitset& operator&=(const DynamicBitset& o) {
        for (size_t i = 0; i < data_.size(); i++) data_[i] &= o.data_[i];
        recount();
        return *this;
    }
    DynamicBitset& operator|=(const DynamicBitset& o) {
        for (size_t i = 0; i < data_.size(); i++) data_[i] |= o.data_[i];
        recount();
        return *this;
    }
    DynamicBitset& operator^=(const DynamicBitset& o) {
        for (size_t i = 0; i < data_.size(); i++) data_[i] ^= o.data_[i];
        recount();
        return *this;
    }

    friend DynamicBitset operator&(DynamicBitset a, const DynamicBitset& b) { return a &= b; }
    friend DynamicBitset operator|(DynamicBitset a, const DynamicBitset& b) { return a |= b; }
    friend DynamicBitset operator^(DynamicBitset a, const DynamicBitset& b) { return a ^= b; }

    DynamicBitset operator~() const {
        DynamicBitset res(*this);
        res.flip();
        return res;
    }

    bool operator==(const DynamicBitset& o) const {
        return n_ == o.n_ && data_ == o.data_;
    }
    bool operator!=(const DynamicBitset& o) const { return !(*this == o); }

    // ----- Shift operators (O(N/W)) ------------------------------------

    DynamicBitset operator<<(size_t sh) const {
        DynamicBitset res(n_);
        if (sh >= n_) return res;
        size_t wsh = sh / BW, bsh = sh % BW;
        for (size_t wi = wsh; wi < data_.size(); wi++) {
            res.data_[wi] = data_[wi - wsh] << bsh;
            if (bsh && wi > wsh)
                res.data_[wi] |= data_[wi - wsh - 1] >> (BW - bsh);
        }
        if (!res.data_.empty()) res.data_.back() &= res.last_mask();
        res.recount();
        return res;
    }

    DynamicBitset operator>>(size_t sh) const {
        DynamicBitset res(n_);
        if (sh >= n_) return res;
        size_t wsh = sh / BW, bsh = sh % BW;
        const size_t nw = data_.size();
        for (size_t wi = 0; wi + wsh < nw; wi++) {
            res.data_[wi] = data_[wi + wsh] >> bsh;
            if (bsh && wi + wsh + 1 < nw)
                res.data_[wi] |= data_[wi + wsh + 1] << (BW - bsh);
        }
        res.recount();
        return res;
    }

    // ----- Resize ------------------------------------------------------

    void resize(size_t new_n, bool fill_val = false) {
        size_t new_nw = words_for(new_n);

        if (new_n > n_ && !data_.empty()) {
            // Fill padding bits in current last word if extending.
            int rem = (int)(n_ % BW);
            if (rem) {
                Word_t pad = ALLONE << rem;
                if (fill_val) data_.back() |= pad;
                else          data_.back() &= ~pad;
            }
        }

        data_.resize(new_nw, fill_val ? ALLONE : Word_t(0));
        n_ = new_n;

        // Mask last word.
        if (!data_.empty()) data_.back() &= last_mask();
        recount();
    }

private:
    // Recompute cnt_ from scratch (used after bulk operations).
    void recount() {
        cnt_ = 0;
        for (auto w : data_) cnt_ += (size_t)__builtin_popcountll(w);
    }
};

#endif // AFDS_DYNAMIC_BITSET
