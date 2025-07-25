#ifndef AFMT_LINEAR
#define AFMT_LINEAR

#include <algorithm>
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

// Strassen's algorithm for square matrices
namespace detail {
    template <class T>
    Matrix<T> strassen(const Matrix<T> &A, const Matrix<T> &B, int threshold = 64) {
        size_t n = A.n();
        if (n <= threshold) {
            Matrix<T> ans(n, n, T());
            for (size_t i = 0; i < n; i++)
                for (size_t k = 0; k < n; k++) {
                    const T &Aik = A.M[i][k];
                    for (size_t j = 0; j < n; j++)
                        ans[i][j] += Aik * B.M[k][j];
                }
            return ans;
        }
        size_t m = n / 2;
        auto sub = [&](const Matrix<T> &X, int r, int c) {
            Matrix<T> res(m, m);
            for (size_t i = 0; i < m; i++)
                for (size_t j = 0; j < m; j++)
                    res[i][j] = X.M[i + r * m][j + c * m];
            return res;
        };
        auto add = [](const Matrix<T> &X, const Matrix<T> &Y) {
            Matrix<T> res(X.n(), X.m());
            for (size_t i = 0; i < X.n(); i++)
                for (size_t j = 0; j < X.m(); j++)
                    res[i][j] = X.M[i][j] + Y.M[i][j];
            return res;
        };
        auto subm = [](const Matrix<T> &X, const Matrix<T> &Y) {
            Matrix<T> res(X.n(), X.m());
            for (size_t i = 0; i < X.n(); i++)
                for (size_t j = 0; j < X.m(); j++)
                    res[i][j] = X.M[i][j] - Y.M[i][j];
            return res;
        };
        Matrix<T> A11 = sub(A, 0, 0), A12 = sub(A, 0, 1), A21 = sub(A, 1, 0), A22 = sub(A, 1, 1);
        Matrix<T> B11 = sub(B, 0, 0), B12 = sub(B, 0, 1), B21 = sub(B, 1, 0), B22 = sub(B, 1, 1);
        auto M1 = strassen(add(A11, A22), add(B11, B22), threshold);
        auto M2 = strassen(add(A21, A22), B11, threshold);
        auto M3 = strassen(A11, subm(B12, B22), threshold);
        auto M4 = strassen(A22, subm(B21, B11), threshold);
        auto M5 = strassen(add(A11, A12), B22, threshold);
        auto M6 = strassen(subm(A21, A11), add(B11, B12), threshold);
        auto M7 = strassen(subm(A12, A22), add(B21, B22), threshold);
        Matrix<T> ans(n, n);
        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < m; j++) {
                ans[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
                ans[i][j + m] = M3[i][j] + M5[i][j];
                ans[i + m][j] = M2[i][j] + M4[i][j];
                ans[i + m][j + m] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
            }
        return ans;
    }
}

template <class T>
Matrix<T> operator*(Matrix<T> A, Matrix<T> B) {
    if (A.n() == A.m() && B.n() == B.m() && A.n() == B.n() && (A.n() & (A.n() - 1)) == 0) {
        // Use Strassen for square matrices with size power of 2
        return detail::strassen(A, B);
    }
    assert(A.m() == B.n());
    Matrix<T> ans(A.n(), B.m());
    for (size_t i = 0; i < A.n(); i++) {
        for (size_t k = 0; k < A.m(); k++) {
            const T &Aik = A[i][k];
            for (size_t j = 0; j < B.m(); j++) {
                ans[i][j] += Aik * B[k][j];
            }
        }
    }
    return ans;
}

template <class T>
std::vector<T> operator*(Matrix<T> A, std::vector<T> B) {
    assert(A.m() == B.size());
    std::vector<T> ans(A.n());
    for (size_t i = 0; i < A.n(); i++) {
        for (size_t j = 0; j < A.m(); j++) {
            ans[i] += A[i][j] * B[j];
        }
    }
    return ans;
}

template <class T>
Matrix<T> power(Matrix<T> M, long long index) {
    assert(M.n() == M.m());
    Matrix<T> ans(M.n());
    while (index) {
        if (index & 1) ans = ans * M;
        index >>= 1, M = M * M;
    }
    return ans;
}

#endif // !AFMT_LINEAR
