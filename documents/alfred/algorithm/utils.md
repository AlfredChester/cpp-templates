---
title: Algorithm Utilities
documentation_of: ./src/alfred/algorithm/utils.hpp
---

## Description

This file provides a set of common algorithm utility functions, including max/min value updates and vector output, to simplify code writing.

## Usage Example

```cpp
#include "utils.hpp"
int x = 1;
chkmax(x, 5); // x = 5
chkmin(x, {2, 3, 4}); // x = 2
std::vector<int> v = {1, 2, 3};
write_vec(v);
```

## Main Features
- Batch max/min update functions
- Supports initializer_list
- Vector output functions, supports single/multi-line

## Important Functions and Time Complexity

| Function    | Description      | Time Complexity |
| ----------- | ---------------- | --------------- |
| `chkmax`    | Max value update | $O(n)$          |
| `chkmin`    | Min value update | $O(n)$          |
| `write_vec` | Output vector    | $O(n)$          |

## Notes
- Useful for common helper operations in contests and daily development.
