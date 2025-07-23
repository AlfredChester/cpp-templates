---
title: Math Utility Functions
documentation_of: ./src/alfred/math/utils.hpp
---

## Description

This file provides various math utility functions, including primality test, GCD, LCM, integer square root, range check, Euler sieve, and random sequence generation.

## Usage Example

```cpp
#include "utils.hpp"
bool p = is_prime(17);
int g = gcd(12, 18);
```

## Main Features
- Primality test (trial division)
- GCD and LCM functions
- Integer square root
- Euler sieve for primes
- Random sequence generator

## Important Functions and Time Complexity

| Function      | Description           | Time Complexity |
| ------------- | --------------------- | --------------- |
| `is_prime`    | Primality test        | $O(\sqrt{n})$   |
| `gcd`         | Compute GCD           | $O(\log n)$     |
| `lcm`         | Compute LCM           | $O(\log n)$     |
| `euler_sieve` | Sieve of Eratosthenes | $O(n)$          |

## Notes
- Primality test is not Miller-Rabin.
- Useful for general math and number theory tasks.
