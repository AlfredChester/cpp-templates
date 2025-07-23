---
title: Grid and Direction Utilities
documentation_of: ./src/alfred/graph/grid.hpp
---

## Description

This file provides utilities for grid-based algorithms, including direction enums, movement, and grid point structures for 2D grids.

## Usage Example

```cpp
#include "grid.hpp"
GridPoint p(2, 3);
GridPoint q = p.move(right);
```

## Main Features
- Direction enum (up, right, down, left)
- GridPoint struct with movement and adjacency
- Helper functions for direction rotation and opposite

## Important Functions and Time Complexity

| Function       | Description               | Time Complexity |
| -------------- | ------------------------- | --------------- |
| `move`         | Move in a direction       | $O(1)$          |
| `adj`          | Get adjacent points       | $O(1)$          |
| `adj_with_dir` | Adjacent points with dirs | $O(1)$          |

## Notes
- Useful for grid-based search and pathfinding algorithms.
- 1-based indexing for in_range checks.
