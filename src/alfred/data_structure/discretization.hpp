#ifndef AFDS_DISCRETIZATION
#define AFDS_DISCRETIZATION

#include <algorithm>
#include <vector>

template <class _Tp>
class Mess {
private:
    std::vector<_Tp> v;
    bool initialized = false;

public:
    Mess(void) = default;
    Mess(std::vector<_Tp> a) : v(a) { init(); }
    inline _Tp origin(int idx) { return v[idx - 1]; }
    inline void insert(_Tp x) { v.push_back(x); }
    template <typename T, typename... V>
    inline void insert(T x, V... v) { insert(x), insert(v...); }
    inline void init(void) {
        std::sort(v.begin(), v.end()), initialized = true;
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    inline void clear(void) { v.clear(), initialized = false; }
    inline int query(_Tp x) {
        if (!initialized) init();
        return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    }
    template <class T>
    inline void set(T &x) { x = query(x); }
    template <typename T, typename... V>
    inline void set(T &x, V... v) { set(x), set(v...); }
    inline bool exist(_Tp x) { return origin(query(x)) == x; }
    inline size_t size(void) noexcept {
        if (!initialized) init();
        return v.size();
    }
};

#endif // AFDS_DISCRETIZATION
