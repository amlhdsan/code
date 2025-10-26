#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

int T;
int n;
int res;

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
        if (b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {

    T = read();
    while(T--) {
        n = read();
        int k = qpow(2, n - 1);
        res = 0;
        for (int i = 1; i <= n; ++i) {
            int l, r, x;
            l = read();
            r = read();
            x = read();
            res |= x;
            res %= MOD;
        }
        writeln(res * k % MOD);
    }

    return 0;
}