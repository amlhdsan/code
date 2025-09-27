#include <bits/stdc++.h>

#define MOD 1000000007
#define int long long

using namespace std;

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
    int res = 1;
    while (b) {
        if (b & 1) res = (int)((1LL * res * a) % MOD);
        a = (int)((1LL * a * a) % MOD);
        b >>= 1;
    }
    return res;
}

inline void solve(int x, int y) {
    long long tx = x;
    long long ans = 1;

    for (long long p = 2; p * p <= tx; ++p) {
        if (tx % p == 0) {
            int cnt = 0;
            while (tx % p == 0) {
                tx /= p;
                ++cnt;
            }
            // compute C(cnt + y - 1, cnt) mod MOD
            long long comb = 1;
            for (int i = 1; i <= cnt; ++i) {
                long long num = ( (long long)y + i - 1 ) % MOD;
                comb = comb * num % MOD;
                comb = comb * qpow(i, MOD - 2) % MOD;
            }
            ans = ans * comb % MOD;
        }
    }
    if (tx > 1) {
        // remaining prime with exponent 1
        int cnt = 1;
        long long comb = 1;
        for (int i = 1; i <= cnt; ++i) {
            long long num = ( (long long)y + i - 1 ) % MOD;
            comb = comb * num % MOD;
            comb = comb * qpow(i, MOD - 2) % MOD;
        }
        ans = ans * comb % MOD;
    }

    writeln((int)ans * qpow(2, y - 1) % MOD);
}

signed main() {

    int T = read();

    while(T--) {
        int x = read();
        int y = read();
        solve(x, y);
    }

    return 0;
}