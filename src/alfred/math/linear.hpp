#ifndef AFMT_LINEAR
#define AFMT_LINEAR

#include <cassert>
#include <vector>

template <class T>
struct Matrix {
    std::vector<std::vector<T>> M;
    Matrix(std::vector<std::vector<T>> _M) : M(_M) {}
    Matrix(int n, int m, T val = T()) : M(n, std::vector<T>(m, val)) {}
    // Generate a diagonal matrix.
    Matrix(std::vector<T> diag) : M(diag.size(), std::vector<T>(diag.size())) {
        for (size_t i = 0; i < diag.size(); i++) {
            M[i][i] = diag[i];
        }
    }
    // Generate a unit matrix.
    Matrix(int n) : M(n, std::vector<T>(n)) {
        for (int i = 0; i < n; i++) M[i][i] = 1;
    }
    inline std::vector<T> &operator[](int n) { return M[n]; }
    inline size_t n(void) { return M.size(); }
    inline size_t m(void) { return M[0].size(); }
};

template <class T>
friend Matrix<T> operator*(Matrix<T> A, Matrix<T> B) {
    assert(A.m() == B.n(), "Must be a legal matrix multiplication");
    Matrix<T> ans(A.n(), B.m());
    for (size_t k = 0; k < A.m(); k++) {
        for (size_t i = 0; i < A.n(); i++) {
            for (size_t j = 0; j < B.m(); j++) {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return ans;
}

template <class T>
friend std::vector<T> operator*(Matrix<T> A, std::vector<T> B) {
    assert(A.m() == B.size(), "Must be a legal matrix multiplication");
    std::vector<T> ans(A.n());
    for (size_t i = 0; i < A.n(); i++) {
        for (size_t j = 0; j < A.m(); j++) {
            ans[i] += A[i][j] * B[j];
        }
    }
    return ans;
}

template <class T>
std::vector<T> solve_equation(
    Matrix<T> M, std::vector<T> res
) {
}

template <class T>
Matrix<T> power(Matrix<T> M, long long index) {
    assert(M.n() == M.m(), "Matrix to be powered must be a square matrix.");
    Matrix<T> ans(M.n());
    while (index) {
        if (index & 1) ans = ans * M;
        index >>= 1, M = M * M;
    }
    return ans;
}

#endif // !AFMT_LINEAR
