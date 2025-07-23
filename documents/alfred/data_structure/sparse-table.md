---
title: Sparse Table
documentation_of: ./src/alfred/data_structure/sparse-table.hpp
---

## Description

This file implements a generic sparse table data structure for efficient static range queries (e.g., min, max, sum) with idempotent operations.

## Usage Example

```cpp
#include "sparse-table.hpp"
SparseTable<int> st({1, 2, 3, 4});
int minv = st.query(1, 3);
```

## Main Features
- Precomputes answers for all intervals of length $2^k$
- Supports idempotent operations (e.g., min, max, gcd)
- Fast range and disjoint queries

## Important Functions and Time Complexity

| Function         | Description             | Time Complexity |
| ---------------- | ----------------------- | --------------- |
| `init`           | Initialize table        | $O(n \log n)$   |
| `query(l, r)`    | Query range [l, r]      | $O(1)$          |
| `disjoint_query` | Disjoint interval query | $O(\log n)$     |

## Notes
- Designed for static arrays and idempotent operations.
- Useful for RMQ and LCA preprocessing.
