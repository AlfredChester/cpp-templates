---
title: Weighted Disjoint Set Union (Weighted DSU)
documentation_of: ./src/alfred/data_structure/dsu/weighted-dsu.hpp
---

## Description

This file implements a weighted Disjoint Set Union (DSU) data structure, which supports union-find operations with additional weight information for each element. It allows merging with a given weight difference and querying the distance between elements.

## Usage Example

```cpp
#include "weighted-dsu.hpp"
WeightedDSU<int> dsu(5);
dsu.merge(1, 2, 3); // a[1] + 3 = a[2]
int dist = dsu.distance(1, 2);
```

## Main Features
- Supports union, find, and weight difference queries
- Maintains weight information for each element
- Allows merging with custom weight relations

## Important Functions and Time Complexity

| Function   | Description                           | Time Complexity |
| ---------- | ------------------------------------- | --------------- |
| `merge`    | Merge two sets with weight            | $O(\alpha(n))$  |
| `find`     | Find representative and update weight | $O(\alpha(n))$  |
| `distance` | Query weight difference               | $O(\alpha(n))$  |
| `same`     | Check if two elements are connected   | $O(\alpha(n))$  |

## Notes
- Useful for problems involving relative weights or equations between elements.
