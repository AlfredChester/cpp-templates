---
title: Sliding Window Utilities
documentation_of: ./src/alfred/data_structure/sliding-window.hpp
---

## Description

This file provides sliding window utilities for 1D and 2D arrays, supporting efficient minimum/maximum queries over windows of fixed size.

## Usage Example

```cpp
#include "sliding-window.hpp"
std::vector<int> a = {1, 3, 2, 5};
auto res = sliding_window(a, 2); // Min in each window of size 2
```

## Main Features
- 1D sliding window minimum/maximum
- 2D grid sliding window support
- Customizable comparison function

## Important Functions and Time Complexity

| Function              | Description       | Time Complexity |
| --------------------- | ----------------- | --------------- |
| `sliding_window`      | 1D window min/max | $O(n)$          |
| `grid_sliding_window` | 2D window min/max | $O(nm)$         |

## Notes
- Default comparison finds minimum; can be customized.
- Useful for range minimum/maximum queries in arrays and matrices.
