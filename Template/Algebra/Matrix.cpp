using ll = long long;
const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<ll>> a;
    int n, m;
    Matrix(int n = 0, int m = 0) : n(n), m(m) {
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i].resize(m);
            for (int j = 0; j < m; j++)
                a[i][j] = 0;
        }
    }
};
Matrix Identity(int n) {
    Matrix mat(n, n);
    for (int i = 0; i < n; i++)
        mat.a[i][i] = 1;
    return mat;
}
Matrix operator*(const Matrix& a, const Matrix& b) {
    Matrix c(a.n, b.m);
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < b.m; j++)
            for (int k = 0; k < a.m; k++)
                c.a[i][j] = (a.a[i][k] * b.a[k][j] % MOD + c.a[i][j]) % MOD;
    return c;
}

Matrix pow(const Matrix& a, ll k) {
    if (k == 0) return Identity(a.n);
    if (k == 1) return a;
    Matrix temp = pow(a, k / 2);
    temp = temp * temp;
    if (k & 1)
        temp = temp * a;
    return temp;
}