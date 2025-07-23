---
title: PBDS Balanced Tree Wrapper
documentation_of: ./src/alfred/data_structure/pbds-balance-tree.hpp
---

## Description

This file provides a type alias for a balanced tree data structure using GNU PBDS, supporting order statistics and customizable comparison and tree types (e.g., red-black tree, splay tree).

## Usage Example

```cpp
#include "pbds-balance-tree.hpp"
BalanceTree<int> tree;
tree.insert(5);
```

## Main Features
- Wrapper for GNU PBDS tree with order statistics
- Supports custom comparison and tree tags
- Can be used as a set with order statistics

## Important Functions and Time Complexity

| Function              | Description                     | Time Complexity |
| --------------------- | ------------------------------- | --------------- |
| `insert`              | Insert an element               | $O(\log n)$     |
| `erase`               | Remove an element               | $O(\log n)$     |
| `find_by_order(k)`    | k-th smallest element (0-based) | $O(\log n)$     |
| `order_of_key(value)` | Number of elements < value      | $O(\log n)$     |

## Notes
- Requires GNU PBDS library support.
- Useful for problems needing order statistics.
