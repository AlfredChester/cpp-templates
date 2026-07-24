---
title: Min Cost Max Flow (SPFA & Primal-Dual)
documentation_of: ./src/alfred/graph/min-cost-maxflow.hpp
---

## Description

Algorithms for finding the minimum cost maximum flow in a flow network. 
This file provides two implementations:
- `MCMF_SPFA`: Uses the Successive Shortest Path (SSP) algorithm with SPFA. It can handle negative cost edges.
- `MCMF_Dijkstra`: Uses the Primal-Dual algorithm with Dijkstra and potentials. It assumes initial edge costs are non-negative, and is generally much faster than SPFA-based algorithms, especially on dense graphs.

## Usage Example

```cpp
#include "min-cost-maxflow.hpp"
#include <iostream>

int main() {
    // Using MCMF_Dijkstra for non-negative cost edges
    MCMF_Dijkstra<int, int> mcmf(4);
    mcmf.add(0, 1, 3, 1); // u, v, cap, cost
    mcmf.add(0, 2, 2, 2);
    mcmf.add(1, 2, 1, 1);
    mcmf.add(1, 3, 2, 3);
    mcmf.add(2, 3, 3, 1);
    
    auto [flow, cost] = mcmf.maxflow(0, 3);
    std::cout << "Max Flow: " << flow << ", Min Cost: " << cost << "\n";
    // Outputs Max Flow: 5, Min Cost: 17
    return 0;
}
```

## Main Features
- Dynamic generic capacities and costs (`Cap`, `Cost`).
- Standard SPFA and Primal-Dual (Dijkstra + Potentials) algorithms using a predecessor array for safe and fast flow augmentation.
- Support for retrieving final flows and residual capacities of edges.

## Important Functions and Time Complexity

| Function | Description | Time Complexity |
| --- | --- | --- |
| `add` | Adds a directed edge with capacity `c` and cost `w` | $O(1)$ |
| `maxflow` (SPFA) | Calculates MCMF from source `s` to sink `t` | $O(F \cdot V E)$ worst-case |
| `maxflow` (Dijkstra) | Calculates MCMF from source `s` to sink `t` | $O(F \cdot E \log V)$ |
| `edges` | Reconstructs the edges and their flows | $O(E)$ |

*(where $F$ is the maximum flow)*

## Notes
- Use `MCMF_Dijkstra` whenever the graph has no negative cost edges initially, as it is much faster and safe from SPFA's worst-case degradation.
- Use `MCMF_SPFA` if the graph contains negative cost edges (but no negative cost cycles).
