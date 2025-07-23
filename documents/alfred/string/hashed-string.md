---
title: Hashed String Utilities
documentation_of: ./src/alfred/string/hashed-string.hpp
---

## Description

This file provides string hashing utilities, including single and double hash structures, for efficient substring comparison and palindrome checking.

## Usage Example

```cpp
#include "hashed-string.hpp"
HashedString hs("abcabc");
bool same = hs.check_same(0, 2, 3, 5);
```

## Main Features
- Single and double hash for strings
- Substring hash and comparison
- Palindrome checking with hashes

## Important Functions and Time Complexity

| Function          | Description              | Time Complexity |
| ----------------- | ------------------------ | --------------- |
| `get_hash`        | Get hash of substring    | $O(1)$          |
| `check_same`      | Compare substrings       | $O(1)$          |
| `check_period`    | Check periodic substring | $O(1)$          |
| `PalindromeCheck` | Palindrome check utility | $O(1)$          |

## Notes
- Indexing is 0-based by default.
- Useful for string matching and palindrome problems.
