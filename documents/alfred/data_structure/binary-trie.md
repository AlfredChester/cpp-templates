---
title: Binary Trie (01-Trie)
documentation_of: ./src/alfred/data_structure/binary-trie.hpp
---

## Description

This file implements a Binary Trie (01-Trie) data structure for efficiently storing and querying binary representations of integers. It supports insertion, minimum/maximum XOR queries, and range queries with upper bounds.

## Usage Example

```cpp
#include "binary-trie.hpp"
BinaryTrie trie;
trie.insert(5);
uint64_t min_xor = trie.query_min(3);
uint64_t max_xor = trie.query_max(3);
```

## Main Features
- Insert and store integers in binary form
- Query for minimum/maximum XOR with a given value
- Query for values with XOR less than an upper bound
- Maintains min/max index for range queries

## Important Functions and Time Complexity

| Function    | Description                   | Time Complexity |
| ----------- | ----------------------------- | --------------- |
| `insert`    | Insert integer into trie      | $O(B)$          |
| `query_min` | Minimize XOR with given value | $O(B)$          |
| `query_max` | Maximize XOR with given value | $O(B)$          |
| `query_ub`  | Query for XOR < upper bound   | $O(B)$          |

Where $B$ is the number of bits (default 30).

## Notes
- Useful for problems involving XOR queries and binary representations.
- Supports index tracking for advanced queries.
