#include <bits/stdc++.h>

#define MOD 1000000007
#define int long long

using namespace std;

int n, k;
int ans = 1;

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

    while(b > 0) {
        if(b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main() {

    n = read();
    k = read();

    for(int i = n + 1; i <= n * 2; ++i) {
        ans = ans * i % MOD;
    }
    for(int i = 1; i <= n + 1; ++i) {
        ans = ans * qpow(i, MOD - 2) % MOD;
    }

    ans = ans * qpow(n, k) % MOD;

    writeln(ans);

    return 0;
}