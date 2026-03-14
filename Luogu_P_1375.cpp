#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
int p;

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
    int ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = ans * a % p;
        }
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}

signed main() {

    n = read();
    p = 1000000007;
    int k1 = 1;
    for(int i = 2; i <= n * 2; ++i) {
        k1 = k1 * i % p;
    }
    int k2 = 1;
    for(int i = 2; i <= n; ++i) {
        k2 = k2 * i % p;
    }

    int k3 = 1;
    for(int i = 2; i <= n + 1; ++i) {
        k3 = k3 * i % p;
    }

    int pp = k1 * qpow(k2, p - 2) % p;
    pp = pp * qpow(k3, p - 2) % p;

    writeln(pp);

    return 0;
}