---
title: Sqrt Decomposition Utility
documentation_of: ./src/alfred/math/sqrt-decomposition.hpp
---

## Description

This file provides a utility function for performing integer sqrt decomposition, dividing a range into intervals with the same quotient.

## Usage Example

```cpp
#include "sqrt-decomposition.hpp"
auto blocks = sqrt_decomposit(10);
```

## Main Features
- Decomposes range [1, n] into intervals with equal n / l
- Useful for block-based algorithms

## Important Functions and Time Complexity

| Function          | Description             | Time Complexity |
| ----------------- | ----------------------- | --------------- |
| `sqrt_decomposit` | Decompose integer range | $O(\sqrt{n})$   |

## Notes
- Useful for block decomposition and optimization.
