#include <bits/stdc++.h>

#define int long long
#define MOD 998244353

using namespace std;

int n, m, p;

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

inline int qpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

inline void cal(int x) {
    write(qpow((m - x) * p % MOD, n, MOD));
    putchar(' ');
}

signed main() {

    n = read();
    m = read();

    p = qpow(m - 1, 998244351, MOD);

    for(int i = 1; i <= m; ++i) {
        cal(i);
    }

    return 0;
}