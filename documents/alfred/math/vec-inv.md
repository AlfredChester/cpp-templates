---
title: Vector Inverse Utility
documentation_of: ./src/alfred/math/vec-inv.hpp
---

## Description

This file implements the VecInv structure for efficiently computing modular inverses of a vector of values, useful for Lagrange interpolation and polynomial operations.

## Usage Example

```cpp
#include "vec-inv.hpp"
std::vector<mint> v = {1, 2, 3};
VecInv<mint> inv(v);
mint inv0 = inv[0];
```

## Main Features
- Precomputes prefix and suffix products
- Efficient modular inverse queries
- Supports operator[] for access

## Important Functions and Time Complexity

| Function     | Description         | Time Complexity |
| ------------ | ------------------- | --------------- |
| `operator[]` | Get modular inverse | $O(1)$          |

## Notes
- Designed for modular arithmetic types.
- Useful for polynomial interpolation and combinatorics.
