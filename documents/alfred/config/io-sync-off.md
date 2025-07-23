---
title: IO Synchronization Off Utility
documentation_of: ./src/alfred/config/io-sync-off.hpp
---

## Description

This file provides a utility function to disable synchronization between C++ standard IO streams and C IO, which can significantly speed up input and output operations in C++ programs.

## Usage Example

```cpp
#include "io-sync-off.hpp"
optimizeIO();
```

## Main Features
- Disables stdio and iostream synchronization
- Unties cin/cout for faster IO

## Important Functions and Time Complexity

| Function     | Description                       | Time Complexity |
| ------------ | --------------------------------- | --------------- |
| `optimizeIO` | Disable IO sync and untie streams | $O(1)$          |

## Notes
- Should be called at the beginning of main() for effect.
- Commonly used in competitive programming.
