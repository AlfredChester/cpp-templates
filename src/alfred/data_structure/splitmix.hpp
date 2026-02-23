#ifndef AFDS_SPLITMIX
#define AFDS_SPLITMIX

template <class T>
struct Splitmix {
    inline T operator()(T x) {
        if (sizeof(T) == 8) {
            T z = (x += 0x9e3779b97f4a7c15);
            z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
            z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
            return z ^ (z >> 31);
        } else {
            T z = (x += 0x9e3779b9);
            z = (z ^ (z >> 16)) * 0x85ebca6b;
            z = (z ^ (z >> 13)) * 0xc2b2ae35;
            return z ^ (z >> 16);
        }
    }
};

// use specialized version for 64bit and 32bit for older c++ standards
// as if constexpr is not supported

template <>
struct Splitmix<unsigned long long> {
    unsigned long long z;
    inline unsigned long long operator()(unsigned long long x) {
        z = (x += 0x9e3779b97f4a7c15);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }
};

template <>
struct Splitmix<unsigned int> {
    unsigned int z;
    inline unsigned int operator()(unsigned int x) {
        z = (x += 0x9e3779b9);
        z = (z ^ (z >> 16)) * 0x85ebca6b;
        z = (z ^ (z >> 13)) * 0xc2b2ae35;
        return z ^ (z >> 16);
    }
};

#endif
