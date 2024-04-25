#include <iostream>

using i128 = __int128;

std::istream &operator>>(std::istream is, i128 &n) {
    std::string s;
    is >> s;
    for (auto c : s) {
        n = n * 10 + (c - '0');
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, i128 n) {
    std::string s;
    while (n) {
        s += '0' + n % 10;
        n /= 10;
    }
    std::reverse(s.begin(), s.end());
    return os << s;
}
