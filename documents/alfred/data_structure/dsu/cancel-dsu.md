---
title: Cancelable Disjoint Set Union (DSU)
documentation_of: ./src/alfred/data_structure/dsu/cancel-dsu.hpp
---

## Description

This file implements a cancelable Disjoint Set Union (DSU) data structure, also known as a union-find with rollback. It supports merging sets, checking connectivity, and undoing previous merge operations efficiently.

## Usage Example

```cpp
#include "cancel-dsu.hpp"
CancelDSU dsu(5);
dsu.merge(1, 2);
dsu.cancel(); // Undo last merge
```

## Main Features
- Supports union, find, and size queries
- Allows rollback (cancel) of previous merge operations
- Maintains history using a stack

## Important Functions and Time Complexity

| Function | Description                         | Time Complexity |
| -------- | ----------------------------------- | --------------- |
| `merge`  | Merge two sets                      | $O(\alpha(n))$  |
| `cancel` | Undo previous merge(s)              | $O(1)$          |
| `find`   | Find representative                 | $O(\alpha(n))$  |
| `same`   | Check if two elements are connected | $O(\alpha(n))$  |

## Notes
- Useful for offline dynamic connectivity and backtracking problems.
