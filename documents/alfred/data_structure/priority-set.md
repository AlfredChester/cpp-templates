---
title: Priority Set
documentation_of: ./src/alfred/data_structure/priority-set.hpp
---

## Description

This file implements a priority set data structure, which combines a priority queue with lazy deletion to efficiently support insert, erase, and top operations.

## Usage Example

```cpp
#include "priority-set.hpp"
PrioritySet<int> ps;
ps.insert(5);
ps.erase(5);
int top = ps.top();
```

## Main Features
- Efficient insert and erase operations
- Supports duplicate elements
- Provides top element access

## Important Functions and Time Complexity

| Function | Description        | Time Complexity |
| -------- | ------------------ | --------------- |
| `insert` | Insert an element  | $O(\log n)$     |
| `erase`  | Lazy erase element | $O(\log n)$     |
| `top`    | Get top element    | $O(\log n)$     |
| `size`   | Get current size   | $O(1)$          |

## Notes
- All erase operations must be valid (element exists).
- Useful for problems requiring efficient priority queue with deletions.
