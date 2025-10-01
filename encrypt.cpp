#include <bits/stdc++.h>

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

inline void exgcd(int a, int b, __int128 &x, __int128 &y) {
    if(!b) {
        x = 1;
        y = 0;
    }
    else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

inline int inverse(int a, int m) { // ax = 1 mod m
    __int128 x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

inline int qpow(int a, int b, int mod) {
    int res = 1;
    while(b > 0) {
        if(b & 1)
            res = (__int128)res * a % mod;
        a = (__int128) a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {

    freopen("encrypt.in", "r", stdin);
    freopen("encrypt.out", "w", stdout);

    int p, q, e;
    __int128 d;
    p = read();
    q = read();
    __int128 n = p * q;
    __int128 phin = (p - 1) * (q - 1);
    e = read();
    d = inverse(e, phin);

    int L = read();
    while(L--) {
        int c = read();
        write(qpow(c, d, n));
        putchar(' ');
    }

    return 0;
}