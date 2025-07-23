---
title: Lowest Common Ancestor (LCA)
documentation_of: ./src/alfred/graph/lca.hpp
---

## Description

This file implements a generic Lowest Common Ancestor (LCA) structure using Euler tour and sparse table, supporting efficient LCA and distance queries on trees.

## Usage Example

```cpp
#include "lca.hpp"
Graph<> g(5);
LCAImpl<> lca(g, 1);
int ancestor = lca.LCA(2, 3);
```

## Main Features
- Supports LCA and distance queries
- Uses Euler tour and sparse table for $O(1)$ LCA
- Works with weighted or unweighted trees

## Important Functions and Time Complexity

| Function | Description            | Time Complexity |
| -------- | ---------------------- | --------------- |
| `LCA`    | Find LCA of two nodes  | $O(1)$          |
| `dis`    | Distance between nodes | $O(1)$          |
| `init`   | Preprocess tree        | $O(n \log n)$   |

## Notes
- Node indices are 1-based by default.
- Useful for tree path and ancestor queries.
