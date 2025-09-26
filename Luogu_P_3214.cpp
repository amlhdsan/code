#include <bits/stdc++.h>

#define MOD 100000007
#define int long long

using namespace std;

int n, m;
int f[1000010];
int A[1000010];
int mmm = 1;

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

inline int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
        y >>= 1;
    }
    return res;
}   

inline void init() {
    A[0] = 1;
    for (int i = 1; i <= 1000000; ++i) {
        A[i] = (A[i - 1] * (qpow(2, n) - 1 - i + 1)) % MOD;
    }
}

inline void c(int n, int m) {

}

signed main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        mmm = mmm * i % MOD;
    }

    // f[i] = A_{2^n - 1}^{i - 1} - f[i - 1] - f[i - 2] * (i - 1) * (2^n - 1 - (i - 2));

    f[0] = 1;

    init();

    for (int i = 1; i <= m; ++i) {
        f[i] = (A[i - 1] - f[i - 1]) % MOD;
        if (f[i] < 0) f[i] += MOD;
        if (i >= 2) {
            f[i] = (f[i] - (1LL * f[i - 2] * (i - 1) % MOD * (A[1] - (i - 2)) % MOD)) % MOD;
            if (f[i] < 0) f[i] += MOD;
        }
    }

    writeln(f[m] * qpow(mmm, MOD - 2) % MOD);

    return 0;
}