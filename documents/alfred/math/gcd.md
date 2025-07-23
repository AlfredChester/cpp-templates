---
title: GCD Utilities
documentation_of: ./src/alfred/math/gcd.hpp
---

## Description

This file provides GCD (greatest common divisor) utilities, including a value-range GCD class for small values and a generic GCD function for all types.

## Usage Example

```cpp
#include "gcd.hpp"
int g = gcd(12, 18);
```

## Main Features
- ValueRangeGCD for small integer ranges
- Generic GCD function for all types
- Euler sieve for prime factorization

## Important Functions and Time Complexity

| Function        | Description              | Time Complexity |
| --------------- | ------------------------ | --------------- |
| `gcd`           | Compute GCD              | $O(\log n)$     |
| `ValueRangeGCD` | Precompute GCD for range | $O(V)$          |

## Notes
- ValueRangeGCD is efficient for small $V$.
- Useful for number theory and factorization tasks.
