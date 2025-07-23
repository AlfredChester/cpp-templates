---
title: Binary Trie (01-Trie)
documentation_of: ./src/alfred/data_structure/binary-trie.hpp
---

## Description

This file implements a Binary Trie (01-Trie) data structure for efficiently storing and querying binary representations of integers. It supports insertion, minimum/maximum XOR queries, and range queries with upper bounds.

本文件实现了支持下标和区间信息维护的 01-Trie（BinaryTrie），可用于集合异或最值、区间下标查询等。

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

- 支持插入、异或最小/最大值查询
- 支持下标区间信息维护
- 支持 upper_bound 异或查询

## Important Functions and Time Complexity

| Function    | Description                   | Time Complexity |
| ----------- | ----------------------------- | --------------- |
| `insert`    | Insert integer into trie      | $O(B)$          |
| `query_min` | Minimize XOR with given value | $O(B)$          |
| `query_max` | Maximize XOR with given value | $O(B)$          |
| `query_ub`  | Query for XOR < upper bound   | $O(B)$          |

| Function    | Description        | Time Complexity |
| ----------- | ------------------ | --------------- |
| `insert`    | 插入一个数         | $O(\log V)$     |
| `query_min` | 查询异或最小值     | $O(\log V)$     |
| `query_max` | 查询异或最大值     | $O(\log V)$     |
| `query_ub`  | 异或小于上界的区间 | $O(\log V)$     |

Where $B$ is the number of bits (default 30).

## Notes
- Useful for problems involving XOR queries and binary representations.
- Supports index tracking for advanced queries.

- 适用于集合异或、区间最值等问题。
- 支持维护插入元素的下标信息。
