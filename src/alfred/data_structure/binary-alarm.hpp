#ifndef AFDS_BINARY_ALARM
#define AFDS_BINARY_ALARM

#include <array>
#include <limits>
#include <numeric>
#include <vector>

/**
 * @brief A 0-indexed data structure, supporting increasing the value
 *        of single position and giving alarms when the sum of the
 *        values of certain sets of indices exceed a threshold.
 *
 * @tparam T The type that fit the maximum absolute value of the array.
 * @tparam V The base-2 logarithm of the maximum modification or alarm. (upper bound)
 */
template <class T, const int V>
struct BinaryAlarm {
    const int n;
    struct Alarm {
        int h;
        T req, rem;
        std::vector<int> pos;
    };
    std::vector<int> _res;
    std::vector<Alarm> alm;
    std::vector<T> a, stat, tmp; // stat: what kinds of alarm are on a certain position.
    std::vector<std::array<std::vector<int>, V>> L;
    BinaryAlarm(const int N) : n(N), a(N), stat(N), tmp(V), L(N) {}
    inline T full(int h) { return (T(1) << h) - 1; }
    inline T next(T v, int h) { return ((v >> h) + 1) << h; }
    inline T udiv(T a, T b) { return (a - 1) / b + 1; }
    inline void rebuild(int id) {
        T tot = 0; // in case T is unsigned.
        for (auto &p : alm[id].pos) tot += a[p];
        if (tot >= alm[id].req) {
            return alm[id].h = -1, _res.push_back(id);
        }
        alm[id].rem = alm[id].req - tot;
        while (full(alm[id].h) * T(alm[id].pos.size()) >= alm[id].rem) alm[id].h--;
        for (auto &p : alm[id].pos) {
            stat[p] |= T(1) << alm[id].h;
            L[p][alm[id].h].push_back(id);
            alm[id].rem -= next(a[p], alm[id].h) - 1 - a[p];
        }
    }
    inline int monitor(const std::vector<int> &pos, T v) {
        alm.emplace_back(V, v, T(0), pos);
        const int id = alm.size() - 1;
        if (v != 0) {
            for (auto &p : pos) {
                alm.back().req += a[p];
            }
            rebuild(id);
        } else _res.push_back(id);
        return id;
    }
    // a[pos] += v, v must be positive.
    inline void increase(int pos, T v) {
        if (v == 0) return;
        std::vector<int> mod;
        T hs = full(std::__lg(a[pos] ^ (a[pos] + v)) + 1) & stat[pos];
        stat[pos] ^= hs;
        while (hs != 0) {
            int h = std::__lg(hs);
            for (auto &id : L[pos][h]) {
                if (alm[id].h == h) mod.push_back(id);
            }
            hs ^= T(1) << h, L[pos][h].clear();
            tmp[h] = next(a[pos] + v, h) - next(a[pos], h);
        }
        a[pos] += v;
        for (auto &id : mod) {
            T wt = tmp[alm[id].h];
            if (alm[id].rem > wt) {
                alm[id].rem -= wt;
                L[pos][alm[id].h].push_back(id);
                stat[pos] |= T(1) << alm[id].h;
            } else rebuild(id);
        }
    }
    inline std::vector<int> fetch(void) {
        return std::exchange(_res, {});
    }
};

#endif
