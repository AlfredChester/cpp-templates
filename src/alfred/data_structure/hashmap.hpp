#ifndef AFDS_HASHMAP
#define AFDS_HASHMAP

#include <utility>
#include <vector>

template <class K, class V>
struct HashedMap {
    using u32 = unsigned int;
    struct Node {
        K key;
        V val;
        u32 ne;
    };
    u32 lim, mask, tot;
    std::vector<u32> fi;
    std::vector<Node> e;
    inline void init(u32 sz) {
        sz += 1;
        u32 lim = 1;
        while (lim < sz) lim <<= 1;
        fi.assign(lim, 0), tot = 0;
        mask = lim - 1, e.resize(sz);
    }
    inline void inc(K x) {
        u32 u = x & mask;
        for (u32 i = fi[u]; i; i = e[i].ne) {
            if (e[i].key == x) {
                e[i].val++;
                return;
            }
        }
        e[++tot] = {x, 1, fi[u]}, fi[u] = tot;
    }
    inline void dec(K x) {
        u32 u = x & mask;
        for (u32 i = fi[u]; i; i = e[i].ne) {
            if (e[i].key == x) {
                e[i].val--;
                return;
            }
        }
        e[++tot] = {x, 1, fi[u]}, fi[u] = tot;
    }
    inline V query(K x) {
        u32 u = x & mask;
        for (u32 i = fi[u]; i; i = e[i].ne) {
            if (e[i].key == x) return e[i].val;
        }
        return 0;
    }
};

#endif
