---
title: Lagrange Interpolation Utilities
documentation_of: ./src/alfred/math/lagrange.hpp
---

## Description

This file implements Lagrange interpolation and related utilities for polynomial interpolation and summing powers efficiently.

## Usage Example

```cpp
#include "lagrange.hpp"
Lagrange<mint> lag(x, y);
mint val = lag.query(5);
```

## Main Features
- Lagrange interpolation for arbitrary points
- Efficient sum of k-th powers
- Continuous Lagrange for consecutive points

## Important Functions and Time Complexity

| Function            | Description                 | Time Complexity |
| ------------------- | --------------------------- | --------------- |
| `query`             | Interpolate at a point      | $O(n)$          |
| `coefficient`       | Get polynomial coefficients | $O(n^2)$        |
| `sum_of_kth_powers` | Sum $1^k+...+n^k$           | $O(k\log k)$    |

## Notes
- Designed for modular arithmetic types.
- Useful for combinatorics and polynomial problems.
