---
title: Disjoint Set Union (DSU)
documentation_of: ./src/alfred/data_structure/dsu/dsu.hpp
---

## Description

This file implements the classic Disjoint Set Union (DSU) or Union-Find data structure, supporting efficient union, find, and size queries. It also provides a directed merge operation.

## Usage Example

```cpp
#include "dsu.hpp"
DSU dsu(5);
dsu.merge(1, 2);
bool connected = dsu.same(1, 2);
```

## Main Features
- Supports union, find, and size queries
- Provides both undirected and directed merge
- Uses path compression and union by size

## Important Functions and Time Complexity

| Function         | Description                         | Time Complexity |
| ---------------- | ----------------------------------- | --------------- |
| `merge`          | Merge two sets                      | $O(\alpha(n))$  |
| `find`           | Find representative                 | $O(\alpha(n))$  |
| `same`           | Check if two elements are connected | $O(\alpha(n))$  |
| `size`           | Get size of set                     | $O(1)$          |
| `directed_merge` | Merge x into y (directed)           | $O(\alpha(n))$  |

## Notes
- Widely used for connectivity queries in graphs.
