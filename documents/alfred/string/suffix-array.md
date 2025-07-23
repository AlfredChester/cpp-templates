---
title: Suffix Array and LCP Utilities
documentation_of: ./src/alfred/string/suffix-array.hpp
---

## Description

This file implements a suffix array and LCP (longest common prefix) array construction for strings, supporting efficient substring and LCP queries.

## Usage Example

```cpp
#include "suffix-array.hpp"
SuffixArray sa("banana");
int lcp = sa.lcp(1, 3);
```

## Main Features
- Suffix array and rank construction
- LCP array and range minimum queries
- Efficient substring comparison

## Important Functions and Time Complexity

| Function | Description         | Time Complexity |
| -------- | ------------------- | --------------- |
| `lcp`    | LCP of two suffixes | $O(1)$          |
| `get_sa` | Get suffix array    | $O(n)$          |
| `get_h`  | Get LCP array       | $O(n)$          |

## Notes
- Internally uses 1-based indexing for construction.
- Useful for string processing and pattern matching.
