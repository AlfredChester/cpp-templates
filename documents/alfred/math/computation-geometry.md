---
title: Computational Geometry Utilities
documentation_of: ./src/alfred/math/computation-geometry.hpp
---

## Description

This file provides basic computational geometry structures and functions, including points, lines, intersection, and distance calculations.

## Usage Example

```cpp
#include "computation-geometry.hpp"
Point<int> p(1, 2), q(3, 4);
int d2 = dis_square(p, q);
```

## Main Features
- Point and line structures
- Intersection and parallel checks
- Distance and on-line checks

## Important Functions and Time Complexity

| Function        | Description            | Time Complexity |
| --------------- | ---------------------- | --------------- |
| `intersect`     | Intersection of lines  | $O(1)$          |
| `point_on_line` | Check if point on line | $O(1)$          |
| `dis_square`    | Squared distance       | $O(1)$          |

## Notes
- Designed for basic geometry problems.
- Not optimized for advanced geometry tasks.
