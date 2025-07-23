---
title: Pair Counting Utilities
documentation_of: ./src/alfred/algorithm/pair-counting.hpp
---

## Description

This file implements a generic pair counting utility, suitable for efficiently counting the number of pairs that satisfy a given comparison function, commonly used for problems like inversion counting.

## Usage Example

```cpp
#include "pair-counting.hpp"
std::vector<int> a = {3, 1, 2};
size_t inv = count_pair(a, std::greater<int>()); // Count inversions
```

## Main Features
- Supports custom comparison functions for pair counting
- Uses merge sort idea, time complexity $O(n \log n)$
- Does not modify the original data (pass by value)

## Important Functions and Time Complexity

| Function     | Description                 | Time Complexity |
| ------------ | --------------------------- | --------------- |
| `count_pair` | Count pairs satisfying comp | $O(n \log n)$   |

## Notes
- Suitable for counting pairs that satisfy any binary relation.
