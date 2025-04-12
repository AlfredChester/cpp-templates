#ifndef AFDS_INFO
#define AFDS_INFO

#include <limits>
#include <numeric>

template <class T>
struct RangeSetTag {
    T val;
    bool useful = false;
    RangeSetTag(void) : useful(false) {}
    template <class InitT>
    RangeSetTag(InitT x) : val(x), useful(true) {}
    RangeSetTag operator+(RangeSetTag &x) {
        return {x.val, x.useful};
    }
    inline void operator+=(RangeSetTag x) {
        val = x.val, useful = x.useful;
    }
};

template <class T>
struct MaxInfo {
    T val;
    MaxInfo(void) { val = std::numeric_limits<T>::min(); }
    template <class InitT>
    MaxInfo(InitT x) { val = x; }
    MaxInfo operator+(MaxInfo &x) {
        return {std::max(val, x.val)};
    }
    inline void operator+=(MaxInfo x) {
        val = std::max(val, x.val);
    }
    inline void operator+=(RangeSetTag<T> &tag) {
        val = tag.val, tag.useful = false;
    }
};

template <class T>
struct MinInfo {
    T val;
    MinInfo(void) { val = std::numeric_limits<T>::max(); }
    template <class InitT>
    MinInfo(InitT x) { val = x; }
    MinInfo operator+(MinInfo &x) {
        return {std::min(val, x.val)};
    }
    inline void operator+=(MinInfo x) {
        val = std::min(val, x.val);
    }
    inline void operator+=(RangeSetTag<T> &tag) {
        val = tag.val, tag.useful = false;
    }
};

template <class T>
struct GcdInfo {
    T val;
    GcdInfo(void) { val = T(); }
    template <class InitT>
    GcdInfo(InitT x) { val = x; }
    GcdInfo operator+(GcdInfo &x) {
#if __cplusplus >= 201703L
        return {std::gcd(x.val, val)};
#else
        return {__gcd(x.val, val)};
#endif
    }
    inline void operator+=(GcdInfo x) {
#if __cplusplus >= 201703L
        val = std::gcd(x.val, val);
#else
        val = __gcd(x.val, val);
#endif
    }
    inline void operator+=(RangeSetTag<T> &tag) {
        val = tag.val, tag.useful = false;
    }
};

#endif
