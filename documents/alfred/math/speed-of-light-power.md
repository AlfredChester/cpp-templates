---
title: Speed of Light Power (SOLPower)
documentation_of: ./src/alfred/math/speed-of-light-power.hpp
---

## Description

This file implements the SOLPower class for fast modular exponentiation using precomputed tables, achieving $O(\sqrt{mod})$ or $O(1)$ time for power queries.

## Usage Example

```cpp
#include "speed-of-light-power.hpp"
SOLPower<2, mint> pow2;
mint val = pow2.power(10);
```

## Main Features
- Precomputes powers for fast queries
- Supports modular arithmetic types
- Efficient for large exponents

## Important Functions and Time Complexity

| Function | Description        | Time Complexity           |
| -------- | ------------------ | ------------------------- |
| `power`  | Compute base^index | $O(1)$ or $O(\sqrt{mod})$ |

## Notes
- Designed for modular integer types.
- Useful for repeated power queries with fixed base.
