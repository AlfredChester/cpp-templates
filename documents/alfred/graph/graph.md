---
title: Graph Data Structure
documentation_of: ./src/alfred/graph/graph.hpp
---

## Description

This file implements a generic graph class supporting both directed and undirected graphs, with optional edge weights and Dijkstra's shortest path algorithm.

## Usage Example

```cpp
#include "graph.hpp"
Graph<> g(5);
g.add_directed(1, 2);
std::vector<int> dist = g.dijkstra(1);
```

## Main Features
- Supports directed and undirected edges
- Optional edge weights (template parameter)
- Dijkstra's algorithm for shortest paths

## Important Functions and Time Complexity

| Function         | Description               | Time Complexity  |
| ---------------- | ------------------------- | ---------------- |
| `add_directed`   | Add directed edge         | $O(1)$           |
| `add_undirected` | Add undirected edge       | $O(1)$           |
| `dijkstra`       | Shortest path from source | $O((n+m)\log n)$ |

## Notes
- Node indices are 1-based by default.
- Suitable for general graph algorithms.
