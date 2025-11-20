#include <bits/stdc++.h>

#define int long long
#define MOD 998244353

using namespace std;

int T, n, m;

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

inline int calc(int a, int b) {
    int xl = 1;
    if (1 - a > xl) xl = 1 - a;
    if (1 + b > xl) xl = 1 + b;
    int xr = n;
    if (n - a < xr) xr = n - a;
    if (n + b < xr) xr = n + b;
    if (xr < xl) return 0;
    int yl = 1;
    if (1 - b > yl) yl = 1 - b;
    if (1 - a > yl) yl = 1 - a;
    int yr = m;
    if (m - b < yr) yr = m - b;
    if (m - a < yr) yr = m - a;
    if (yr < yl) return 0;
    int nx = xr - xl + 1;
    int ny = yr - yl + 1;
    return nx * ny;
}

inline void solve() {
    n = read();
    m = read();
    __int128 sum = 0;
    for (int a = -(n - 1); a <= n - 1; ++a) {
        for (int b = -(m - 1); b <= m - 1; ++b) {
            if (a == 0 && b == 0) continue;
            sum += calc(a, b);
        }
    }
    writeln(sum % MOD);
}

signed main() {
    T = read();
    while (T--) solve();
    return 0;
}