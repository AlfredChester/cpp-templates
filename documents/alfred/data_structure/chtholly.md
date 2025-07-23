---
title: Chtholly Tree Data Structure
documentation_of: ./src/alfred/data_structure/chtholly.hpp
---

## Description

This file implements the Chtholly Tree data structure, which is a set-based interval management structure supporting fast interval assignment, modification, and queries. It is commonly used for range updates and queries on intervals.

## Usage Example

```cpp
#include "chtholly.hpp"
ChthollyTree<int> tree(10, 0); // Range [0,10] initialized to 0
tree.assign(2, 5, 3); // Set [2,5] to 3
```

## Main Features
- Efficient interval splitting and assignment
- Supports custom modification and query functions on intervals
- Uses std::set for ordered interval management

## Important Functions and Time Complexity

| Function | Description                  | Time Complexity |
| -------- | ---------------------------- | --------------- |
| `assign` | Assign value to interval     | $O(\log n)$     |
| `modify` | Modify interval with functor | $O(\log n)$     |
| `query`  | Query interval with functor  | $O(\log n)$     |

## Notes
- Useful for range assignment and query problems.
- Intervals are managed as [l, r] inclusive.
