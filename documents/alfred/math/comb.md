---
title: Combination Utilities
documentation_of: ./src/alfred/math/comb.hpp
---

## Description

This file implements a generic combinatorics utility class `Comb` for efficient computation of factorials, inverse factorials, modular inverses, binomial coefficients, and permutations, all under a given modular integer type.

## Usage Example

```cpp
#include "comb.hpp"
Comb<mint> comb(1000000); // Precompute up to 1e6
mint c = comb.binom(10, 3); // Compute C(10, 3)
```

## Main Features
- Precomputes factorials, inverse factorials, and modular inverses up to $n$
- Efficient calculation of binomial and permutation coefficients
- Lazy extension: automatically grows precomputed arrays as needed

## Important Functions and Time Complexity

| Function      | Description             | Time Complexity |
| ------------- | ----------------------- | --------------- |
| `init(m)`     | Precompute up to $m$    | $O(m-n)$        |
| `fac(m)`      | $m!$                    | $O(1)$          |
| `invfac(m)`   | Modular inverse of $m!$ | $O(1)$          |
| `inv(m)`      | Modular inverse of $m$  | $O(1)$          |
| `binom(n, m)` | Binomial coefficient    | $O(1)$          |
| `perm(n, m)`  | Permutation coefficient | $O(1)$          |

- All $O(1)$ queries require $m \leq n$ (precomputed), otherwise $O(m-n)$ for extension.

## Notes
- Designed for use with modular integer types (e.g., ModInt).
- Handles negative and out-of-range queries gracefully by returning zero.
