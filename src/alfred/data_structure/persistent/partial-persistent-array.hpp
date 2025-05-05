#ifndef AFDS_PARTIAL_PERSISTENT
#define AFDS_PARTIAL_PERSISTENT

#include <vector>

// Partial Persistent Array.
// UUID Allocation: begin from zero.
template <class T>
class PPArray {
private:
    int uuid = 0; // the last uuid allocated.
    std::vector<std::vector<std::pair<T, int>>> vec;

public:
    PPArray(void) = default;
    PPArray(int n) : vec(n) {}
    PPArray(std::vector<T> _v) : vec(_v.size()) {
        for (size_t i = 0; i < _v.size(); i++) {
            vec[i].push_back(std::make_pair(_v[i], 0));
        }
    }
    size_t size(void) { return vec.size(); }
    inline int set(int pos, T val, bool new_v = true) {
        if (new_v) uuid += 1;
        vec[pos].push_back(std::make_pair(uuid, val));
        return uuid;
    }
    inline const T get(int pos, int uuid) {
        if (vec[pos].empty()) return T();
        if (vec[pos][0].second > uuid) return T();
        int L = 0, R = vec[pos].size() - 1, mid;
        while (L < R) {
            mid = (L + R + 1) >> 1;
            if (vec[pos][mid].second <= uuid) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        return vec[pos][L].first;
    }
};

#endif
