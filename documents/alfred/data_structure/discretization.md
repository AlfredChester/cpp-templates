---
title: Discretization Utilities
documentation_of: ./src/alfred/data_structure/discretization.hpp
---

## Description

本文件实现了通用离散化工具类 `Mess`，用于将任意可比较类型的值映射到连续整数区间，便于后续高效处理。

This file provides the Mess class, a utility for discretizing values in a vector, mapping them to a compact index range. It supports insertion, initialization, querying, and checking existence of values.

## Usage Example

```cpp
#include "discretization.hpp"
std::vector<int> a = {100, 200, 100};
Mess<int> mess(a);
int idx = mess.query(200); // 查询 200 离散化后的编号
```

```cpp
#include "discretization.hpp"
std::vector<int> a = {5, 2, 7};
Mess<int> mess(a);
int idx = mess.query(5); // Get discrete index of 5
```

## Main Features
- 支持批量插入、自动去重排序
- 支持原值与离散编号互查
- 支持判断元素是否存在

Discretizes values to compact indices
Supports batch insertion and initialization
Query for discrete index and check existence

## Important Functions and Time Complexity

| Function | Description        | Time Complexity |
| -------- | ------------------ | --------------- |
| `insert` | 插入元素           | $O(1)$          |
| `init`   | 初始化（排序去重） | $O(n \log n)$   |
| `query`  | 查询离散编号       | $O(\log n)$     |
| `exist`  | 判断元素是否存在   | $O(\log n)$     |

## Notes
- 适用于需要离散化处理的场景。
- 支持任意可比较类型。

Useful for coordinate compression and mapping values to indices.
