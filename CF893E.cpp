#include <bits/stdc++.h>

#define MOD 1000000007

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
        if (b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

inline void read() {
    
}

inline void solve(int x, int y) {
    // x = p1^a1 * p2^a2 * ... * pk^ak

    // ans = \sum C_{a1 + y - 1}^{y - 1} % MOD

    int ans = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            ans = (ans * (cnt + y - 1)) % MOD;
        }
    }

    writeln(ans * qpow(2, y - 1) % MOD);
}

int main() {

    int T = read();

    while(T--) {
        int x = read();
        int y = read();
        solve(x, y);
    }

    return 0;
}