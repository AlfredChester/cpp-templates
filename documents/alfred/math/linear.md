---
title: Matrix and Linear Algebra Utilities
documentation_of: ./src/alfred/math/linear.hpp
---

## Description

This file provides matrix and linear algebra utilities, including matrix multiplication, exponentiation, and vector multiplication.

## Usage Example

```cpp
#include "linear.hpp"
Matrix<int> A(2, 2, 1);
Matrix<int> B(2, 2, 2);
Matrix<int> C = A * B;
```

## Main Features
- Matrix multiplication and power
- Vector-matrix multiplication
- Diagonal and unit matrix construction

## Important Functions and Time Complexity

| Function    | Description           | Time Complexity |
| ----------- | --------------------- | --------------- |
| `operator*` | Matrix multiplication | $O(n^3)$        |
| `power`     | Matrix exponentiation | $O(n^3\log k)$  |

## Notes
- Designed for generic types supporting arithmetic.
- Useful for DP and linear recurrence problems.
