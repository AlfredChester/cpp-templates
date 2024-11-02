#include <bits/stdc++.h>

template <class T, class Comp = std::less<T>>
class PrioritySet { // warning: all erase operations must be legal.
private:
    std::priority_queue<T, std::vector<T>, Comp> data;
    std::priority_queue<T, std::vector<T>, Comp> erased;

public:
    explicit PrioritySet(void) : data(), erased() {};
    explicit PrioritySet(std::vector<T> &init) {
        for (auto &v : init) {
            insert(v);
        }
    }
    inline void insert(const T &&x) { data.push(x); }
    inline void erase(const T &&x) { erased.push(x); }
    inline T &top(void) noexcept {
        assert(data.size() >= erased.size());
        while (!erased.empty() && data.top() == erased.top()) {
            data.pop(), erased.pop();
        }
        return data.top();
    }
    inline size_t size(void) {
        return data.size() - erased.size();
    }
};