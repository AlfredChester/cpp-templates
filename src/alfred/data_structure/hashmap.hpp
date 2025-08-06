#ifndef AFDS_HASHMAP
#define AFDS_HASHMAP

#include <utility>
#include <vector>

template <class K, class V, size_t SIZE = 3301>
struct HashMap {
    std::vector<std::pair<K, V>> vec[SIZE];
    HashMap(void) {}
    inline int hash_key(K key) { return key % SIZE; }
    inline auto find_it(int h, K key) {
        return std::find_if(vec[h].begin(), vec[h].end(), [&](auto kv) {
            return kv.first == key;
        });
    }
    inline void inc(K key) {
        int h = hash_key(key);
        auto it = find_it(h, key);
        if (it == vec[h].end()) {
            vec[h].emplace_back(key, 1);
            return;
        }
        it->second++;
    }
    inline void dec(K key) {
        int h = hash_key(key);
        auto it = find_it(h, key);
        if (it == vec[h].end()) {
            return;
        }
        it->second--;
        if (it->second == 0) {
            vec[h].erase(it);
        }
    }
    inline V get(K key) {
        int h = hash_key(key);
        auto it = find_it(h, key);
        if (it == vec[h].end()) {
            return 0;
        }
        return it->second;
    }
}

#endif
