---
title: Fast Input/Output Utilities
documentation_of: ./src/alfred/config/fast-io.hpp
---

## Description

This file provides fast input and output utilities for C++, including a custom FastIO class for buffered reading and writing, as well as template functions for fast reading and writing of integers and modular integers.

## Usage Example

```cpp
#include "fast-io.hpp"
int x;
fast_read(x);
write(x);
writeln(x);
```

## Main Features
- Fast buffered input and output
- Supports reading and writing of integers and modular integer types
- Allows resizing of the input buffer
- Variadic template for reading multiple variables

## Important Functions and Time Complexity

| Function     | Description                    | Time Complexity |
| ------------ | ------------------------------ | --------------- |
| `fast_read`  | Fast read integer(s)           | $O(1)$ per int  |
| `write`      | Fast write integer/modular int | $O(\log n)$     |
| `writeln`    | Fast write with newline        | $O(\log n)$     |
| `reset_size` | Resize the input buffer        | $O(1)$          |

## Notes
- Useful for competitive programming and scenarios requiring high-performance IO.
