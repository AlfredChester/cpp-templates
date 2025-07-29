---
title: Cartesian Tree Construction.
documentation_of: ./src/alfred/data_structure/cartesian.hpp
---

## Description

This module provides a function to build a Cartesian tree from a given vector in O(n) time. A Cartesian tree is a binary tree where each node's value is greater than the values of its children, and it is constructed based on the order of elements in the input vector.

## Usage Example

```cpp
#include "cartesian.hpp"
std::vector<int> a = {3, 1, 2};
auto res = cartesian(a); // returns a vector of pairs representing ls and rs of each node.
```

## Main Features
- Supports custom comparison functions for building Cartesian trees based on different criteria.
- Uses monostack algorithm, time complexity $O(n)$
- Does not modify the original data (pass by value)

## Important Functions and Time Complexity

| Function    | Description                                                           | Time Complexity |
| ----------- | --------------------------------------------------------------------- | --------------- |
| `cartesian` | Build a cartesian tree based on the given array and comparison method | $O(n)$          |

