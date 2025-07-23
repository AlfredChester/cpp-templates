---
title: Discretization Utilities
documentation_of: ./src/alfred/data_structure/discretization.hpp
---

## Description

This file provides the Mess class, a utility for discretizing values in a vector, mapping them to a compact index range. It supports insertion, initialization, querying, and checking existence of values.

## Usage Example

```cpp
#include "discretization.hpp"
std::vector<int> a = {5, 2, 7};
Mess<int> mess(a);
int idx = mess.query(5); // Get discrete index of 5
```

## Main Features
- Discretizes values to compact indices
- Supports batch insertion and initialization
- Query for discrete index and check existence

## Important Functions and Time Complexity

| Function | Description                       | Time Complexity |
| -------- | --------------------------------- | --------------- |
| `insert` | Insert value                      | $O(1)$          |
| `init`   | Initialize and sort unique values | $O(n \log n)$   |
| `query`  | Get discrete index                | $O(\log n)$     |
| `exist`  | Check if value exists             | $O(\log n)$     |

## Notes
- Useful for coordinate compression and mapping values to indices.
