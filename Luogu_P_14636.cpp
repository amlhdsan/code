#include <bits/stdc++.h>

#define N 10010
#define MOD 998244353

using namespace std;

int c, t;
int n, m;
int a[N];
int C[N][N];

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

inline int qpow(int a, int b) {
    int ret = 1;
    while(b > 0) {
        if(b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ret % MOD;
}

inline void init() {
    C[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

inline void solve() {
    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    sort(a + 1, a + 1 + n);

    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        int pos = 0;

        for(int j = i + 1; j <= n; ++j) {
            if(a[i] == a[j])
                continue;
            if(m - 2 - n + j < 0)
                continue;
            if(a[j] >= 2 * a[i])
                break;

            while(pos < n && a[pos + 1] < a[j] - a[i]) {
                ++pos;
            }

            ans += C[n - i - 1][m - 2 - n + j] * 1LL * qpow(2, pos) % MOD;
            ans %= MOD;
        }
    }

    writeln((qpow(2, n) - ans + MOD) % MOD);
}

int main() {

    init();

    c = read();
    t = read();

    while(t--) {
        solve();
    }

    return 0;
}