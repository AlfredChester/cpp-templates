---
title: Appear Statistics Data Structure
documentation_of: ./src/alfred/data_structure/appear-statistics.hpp
---

## Description

This file implements the `AppearStats` class, a data structure for efficiently tracking the positions and counts of occurrences of elements in a sequence, supporting fast queries for the first, last, and count of an element in a given range.

## Usage Example

```cpp
#include "appear-statistics.hpp"
std::vector<int> a = {1, 2, 1, 3, 2};
AppearStats<int> stats(a);
int first_pos = stats.first(0, 4, 2); // First occurrence of 2 in [0,4]
int count = stats.count(0, 4, 1);     // Count of 1 in [0,4]
```

## Main Features
- Tracks all positions of each unique element
- Supports fast queries for first/last occurrence and count in a range
- Uses discretization for efficient storage

## Important Functions and Time Complexity

| Function | Description                | Time Complexity |
| -------- | -------------------------- | --------------- |
| `first`  | First occurrence in range  | $O(\log n)$     |
| `last`   | Last occurrence in range   | $O(\log n)$     |
| `count`  | Count occurrences in range | $O(\log n)$     |

## Notes
- Useful for range queries on static arrays.
- Indexing is flexible with a base parameter.
