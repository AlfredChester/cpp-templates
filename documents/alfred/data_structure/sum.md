---
title: Prefix, Grid, and Subset Sum Structures
documentation_of: ./src/alfred/data_structure/sum.hpp
---

## Description

This file provides classes for prefix sum, grid sum, and subset sum, supporting efficient range sum queries in 1D, 2D, and subset spaces.

## Usage Example

```cpp
#include "sum.hpp"
std::vector<int> a = {1, 2, 3};
Sum<int> sum(a);
int s = sum.query(0, 2); // Sum in [0,2]
```

## Main Features
- Prefix sum for 1D arrays
- Grid sum for 2D arrays
- Subset sum for all subsets

## Important Functions and Time Complexity

| Function  | Description       | Time Complexity |
| --------- | ----------------- | --------------- |
| `query`   | Range sum query   | $O(1)$          |
| `init`    | Initialize sums   | $O(n)$/$O(nm)$  |
| `pre/suf` | Prefix/suffix sum | $O(1)$          |

## Notes
- Subset sum supports all $2^n$ subsets.
- Useful for range sum and subset sum queries.
