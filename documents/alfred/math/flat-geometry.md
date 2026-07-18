---
title: Flat Geometry
documentation_of: ./src/alfred/math/flat-geometry.hpp
---

## Description

Modern C++ 2D computational geometry template designed for high performance and strict mathematical correctness. It provides `Vec` and `Point` structures, fundamental operations (dot/cross products, norms), geometric queries (distance, projection, reflection), polar sorting, and an $O(N \log N)$ monotone chain algorithm for convex hull generation. It is fully compatible with C++17.

## Usage Example

```cpp
#include "flat-geometry.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<Point<double>> P = { {0, 0}, {2, 0}, {0, 2}, {1, 1}, {2, 2} };
    
    // Monotone chain convex hull (O(N log N))
    auto hull = convex_hull(P);
    
    for (auto &pt : hull) {
        std::cout << pt.x << " " << pt.y << "\n";
    }
    
    // Lines, distance and projection
    Line<double> line(Point<double>(0, 0), Point<double>(2, 2));
    Point<double> p(0, 2);
    
    std::cout << "Distance: " << distance(p, line) << "\n";
    std::cout << "Projection: " << projection(p, line) << "\n";
    std::cout << "Polygon Area: " << polygon_area(hull) << "\n";
    
    return 0;
}
```

## Main Features
- Standardised `Point<T>` and `Vec<T>` structs avoiding heavy encapsulation for superior runtime performance.
- Fast, exact lexicographical sorting safe for `std::sort`.
- Safe floating point comparisons via `sgn(x, eps)` function which elegantly bypasses EPS overhead for integer coordinates.
- Geometry primitives: `Line<T>`, `Segment<T>`.
- Geometric queries: `distance`, `projection`, `reflection`, and `polygon_area`.
- Counter-clockwise point rotation via `rotate(v, angle)` and `rotate90(v)`.
- `PolarAngleComparator` for robust counter-clockwise sorting of points around a center.
- Monotone Chain algorithm for `convex_hull`, algorithmically outperforming classic Graham's Scan. 

## Important Functions and Time Complexity

| Function | Description | Time Complexity |
| -------- | ----------- | --------------- |
| `dot` | Computes the dot product of two vectors | $O(1)$ |
| `cross` | Computes the cross product of two vectors | $O(1)$ |
| `norm` / `norm2` | Euclidean distance and squared distance from origin | $O(1)$ |
| `rotate` / `rotate90` | Rotates a vector counter-clockwise | $O(1)$ |
| `projection` | Computes the projection of a point onto a line | $O(1)$ |
| `reflection` | Computes the reflection of a point across a line | $O(1)$ |
| `distance` | Shortest distance from a point to a line | $O(1)$ |
| `polygon_area` | Area of a given polygon | $O(N)$ |
| `convex_hull` | Generates a 2D convex hull from a set of points using Monotone Chain | $O(N \log N)$ |

## Notes
- To maximise performance and avoid `std::sort` invalid strict weak ordering faults, this template does not wrap floating point coordinates into an EPS-checking struct. Instead, exact `<` comparison is natively provided for point sorting, and users should use `sgn()` for safe equality or crossing direction checks.
- The `convex_hull` algorithm accepts a `strict` flag (default `true`) which dictates whether collinear points on the hull edges should be excluded.
