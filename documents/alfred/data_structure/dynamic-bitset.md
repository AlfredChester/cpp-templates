---
title: Dynamic Bitset
documentation_of: ./src/alfred/data_structure/dynamic-bitset.hpp
---

## Description

A runtime-sized bitset backed by 64-bit words (`unsigned long long`).
It provides O(1) single-bit operations with a popcount cache, O(N/W)
bulk operations, and O(N/W) next/previous-bit scans that use
`__builtin_ctzll` / `__builtin_clzll` instead of inner loops for
maximum practical performance.

## Usage Example

```cpp
#include "dynamic-bitset.hpp"

DynamicBitset bits(100);          // 100-bit set, all zero
bits.set(5);                       // set bit 5
bool v   = bits.test(5);           // true
int  nxt = bits.suf(0, true);      // 5  (first set bit >= 0, inclusive)
int  prv = bits.pre(99, true);     // 5  (last set bit <= 99, inclusive)

// String constructor
DynamicBitset bits2(5, "10110");   // bits 0,2,3 are set
bits2.flip();                      // bulk flip
size_t cnt = bits2.count();        // popcount
```

## Main Features

- Dynamic size bitset; can be `resize()`-d at any time.
- Maintains a popcount cache so `count()` is O(1).
- Bulk `set()`, `reset()`, `flip()` in O(N/W).
- Bitwise `&=`, `|=`, `^=`, `~`, `<<`, `>>` operators in O(N/W).
- `suf` / `pre` use hardware bit-scan intrinsics for fast next/prev queries.

## Important Functions and Time Complexity

| Function / Operator        | Description                                    | Time Complexity |
| -------------------------- | ---------------------------------------------- | --------------- |
| `DynamicBitset(n)`         | Construct all-zero bitset of size n            | $O(N/W)$        |
| `DynamicBitset(n, str)`    | Construct from `'0'`/`'1'` string             | $O(N/W)$        |
| `set(i, val=true)`         | Set bit i to val (branchless cnt update)       | $O(1)$          |
| `reset(i)`                 | Clear bit i                                    | $O(1)$          |
| `flip(i)`                  | Flip bit i                                     | $O(1)$          |
| `test(i)`                  | Read bit i (returns 0 or 1)                    | $O(1)$          |
| `count()`                  | Popcount (cached)                              | $O(1)$          |
| `set()` / `reset()` / `flip()` | Bulk set / clear / flip all bits          | $O(N/W)$        |
| `suf(i, contain, val)`     | Next index ≥ i (or > i) with test==val        | $O(N/W)$        |
| `pre(i, contain, val)`     | Prev index ≤ i (or < i) with test==val        | $O(N/W)$        |
| `&=` / `\|=` / `^=`       | Bitwise compound assignment                    | $O(N/W)$        |
| `~` / `<<` / `>>`         | Bitwise complement / left-shift / right-shift  | $O(N/W)$        |
| `resize(n, fill=false)`    | Resize to n bits                               | $O(N/W)$        |

## Notes

- All indices are 0-based.
- `suf` / `pre` return `-1` when no matching bit exists.
- The `val` parameter of `suf` / `pre` selects whether to search for a
  set bit (`val=true`, default) or an unset bit (`val=false`).
- Shifting by `s` bits in `<<` moves bit `i` to position `i + s`
  (like `std::bitset`).
- Bitwise operators require both operands to have the same size.
