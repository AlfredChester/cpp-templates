---
title: Partial Persistent Array
documentation_of: ./src/alfred/data_structure/persistent/partial-persistent-array.hpp
---

## Description

This file implements a partial persistent array (PPArray), which allows you to set and get values at different versions (UUIDs), supporting efficient rollback and versioned queries.

## Usage Example

```cpp
#include "partial-persistent-array.hpp"
PPArray<int> arr(5);
int v1 = arr.set(2, 10); // Set index 2 to 10, new version
int val = arr.get(2, v1); // Get value at index 2 in version v1
```

## Main Features
- Supports versioned set and get operations
- Efficient binary search for historical values
- Each set can create a new version (UUID)

## Important Functions and Time Complexity

| Function | Description                       | Time Complexity |
| -------- | --------------------------------- | --------------- |
| `set`    | Set value, optionally new version | $O(1)$          |
| `get`    | Get value at version              | $O(\log k)$     |

## Notes
- Useful for rollback and persistent data structure problems.
- Versioning is managed by UUIDs.
