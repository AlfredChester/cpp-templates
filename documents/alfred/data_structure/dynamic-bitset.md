---
title: Dynamic Bitset
documentation_of: ./src/alfred/data_structure/dynamic-bitset.hpp
---

## Description

This file implements a dynamic bitset class, which provides a resizable bitset supporting efficient bit operations, queries, and range searches. It is similar to std::bitset but with dynamic size.

## Usage Example

```cpp
#include "dynamic-bitset.hpp"
DynamicBitset bits(100);
bits.set(5);
bool is_set = bits.test(5);
```

## Main Features
- Dynamic size bitset with efficient bit operations
- Supports set, reset, flip, and test operations
- Range queries for previous/next set or unset bit

## Important Functions and Time Complexity

| Function | Description                 | Time Complexity |
| -------- | --------------------------- | --------------- |
| `set`    | Set or clear a bit          | $O(1)$          |
| `test`   | Test if a bit is set        | $O(1)$          |
| `flip`   | Flip a bit                  | $O(1)$          |
| `pre`    | Find previous set/unset bit | $O(\log n)$     |
| `suf`    | Find next set/unset bit     | $O(\log n)$     |

## Notes
- Useful for problems requiring dynamic bit manipulation.
- TODO: Resize and bitwise operators are not implemented.
