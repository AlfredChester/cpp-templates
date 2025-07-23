---
title: ModInt (Modular Integer)
documentation_of: ./src/alfred/math/mod-int.hpp
---

## Description

This file provides high-performance modular integer types for both static and dynamic moduli:

- `ModInt<M>`: A template class for modular arithmetic with a compile-time constant modulus $M$.
- `DynamicModInt`: A class for modular arithmetic with a runtime-configurable modulus.

Both types support efficient modular addition, subtraction, multiplication, division (via modular inverse), exponentiation, and stream input/output.

## Usage Example

```cpp
#include "mod-int.hpp"
using mint = ModInt<1000000007>;
mint a = 2, b = 3;
a += b; // a = 5
std::cout << a << std::endl;

DynamicModInt::set_mod(998244353);
DynamicModInt x = 10, y = 20;
x *= y; // x = 200
std::cin >> x;
```

## Main Features
- Static and dynamic modulus support
- Efficient modular arithmetic operations
- Stream input/output support
- Suitable for competitive programming and number theory

## Important Functions and Time Complexity

| Function        | Description                    | Time Complexity |
| --------------- | ------------------------------ | --------------- |
| `operator+=`    | Modular addition               | $O(1)$          |
| `operator-=`    | Modular subtraction            | $O(1)$          |
| `operator*=`    | Modular multiplication         | $O(1)$          |
| `operator/=`    | Modular division (via inverse) | $O(\log M)$     |
| `pow(n)`        | Modular exponentiation         | $O(\log n)$     |
| `inv()`         | Modular inverse (Fermat/Egcd)  | $O(\log M)$     |
| `operator<<,>>` | Stream output/input            | $O(1)$          |

- For `ModInt<M>`, inverse uses Fermat's little theorem (when $M$ is prime).
- For `DynamicModInt`, inverse uses extended Euclidean algorithm.

## Notes
- All operations are safe for negative and large integer inputs.
- The interface is designed to be intuitive and efficient for both static and dynamic modulus scenarios.
