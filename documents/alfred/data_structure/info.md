---
title: Range Information Structures
documentation_of: ./src/alfred/data_structure/info.hpp
---

## Description

This file provides several structures for maintaining range information, such as maximum, minimum, sum, and GCD, as well as a tag for range set operations. These are useful for segment trees and other range query data structures.

## Usage Example

```cpp
#include "info.hpp"
MaxInfo<int> maxv(5), maxu(3);
maxv += maxu;
```

## Main Features
- Structures for max, min, sum, and GCD information
- Range set tag for lazy propagation
- Operator overloading for combining and updating info

## Important Functions and Time Complexity

| Structure     | Description                  |
| ------------- | ---------------------------- |
| `MaxInfo`     | Maintains maximum value      |
| `MinInfo`     | Maintains minimum value      |
| `SumInfo`     | Maintains sum and length     |
| `GcdInfo`     | Maintains GCD value          |
| `RangeSetTag` | Tag for range set operations |

## Notes
- Designed for use in segment trees and range query data structures.
- Supports lazy propagation and info combination.
