---
title: Fenwick Tree (Binary Indexed Tree)
documentation_of: ./src/alfred/data_structure/fenwick.hpp
---

## Description

This file implements the Fenwick Tree (Binary Indexed Tree) data structure, which supports efficient prefix sum and range sum queries, as well as point updates. It is generic and works with any type supporting addition and subtraction.

## Usage Example

```cpp
#include "fenwick.hpp"
Fenwick<int> bit(10);
bit.update(3, 5); // Add 5 to position 3
int sum = bit.query(0, 3); // Query sum in [0,3]
```

## Main Features
- Efficient prefix and range sum queries
- Point updates
- Generic for any type with + and - operators
- Supports finding the k-th smallest prefix sum

## Important Functions and Time Complexity

| Function | Description                   | Time Complexity |
| -------- | ----------------------------- | --------------- |
| `update` | Add value to position         | $O(\log n)$     |
| `query`  | Prefix/range sum query        | $O(\log n)$     |
| `clear`  | Reset all values              | $O(n)$          |
| `kth`    | Find k-th prefix sum position | $O(\log n)$     |

## Notes
- Widely used for range sum and frequency queries.
