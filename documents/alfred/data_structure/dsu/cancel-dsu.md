---
title: Cancelable Disjoint Set Union (DSU)
documentation_of: ./src/alfred/data_structure/dsu/cancel-dsu.hpp
---

## Description

本文件实现了支持撤销操作的并查集（Cancelable DSU），可用于可回溯的合并查找问题。

This file implements a cancelable Disjoint Set Union (DSU) data structure, also known as a union-find with rollback. It supports merging sets, checking connectivity, and undoing previous merge operations efficiently.

## Usage Example

```cpp
#include "cancel-dsu.hpp"
CancelDSU dsu(5);
dsu.merge(1, 2);
dsu.cancel(); // 撤销上一次合并
dsu.cancel(); // Undo last merge
```

## Main Features
- 支持撤销合并操作
- 支持集合大小查询
- 适合可回溯并查集场景
- Supports union, find, and size queries
- Allows rollback (cancel) of previous merge operations
- Maintains history using a stack

## Important Functions and Time Complexity

| Function | Description                         | Time Complexity |
| -------- | ----------------------------------- | --------------- |
| `merge`  | 合并集合                            | $O(\alpha(n))$  |
| `cancel` | 撤销合并                            | $O(1)$          |
| `find`   | 查找根节点                          | $O(\alpha(n))$  |
| `same`   | Check if two elements are connected | $O(\alpha(n))$  |

## Notes
- 适用于需要撤销操作的并查集问题。
- Useful for offline dynamic connectivity and backtracking problems.
