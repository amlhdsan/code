#include <bits/stdc++.h>

#define int unsigned long long

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

inline void exgcd(int a, int b, int &x, int &y) {
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
    int x, y;
    exgcd(a, m, x, y);
    return (x % m + m) % m;
}

inline int qpow(int a, int b, int mod) {
    int res = 1;
    while(b > 0) {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

signed main() {

    int p, q, e, n, phin, d;
    p = read();
    q = read();
    n = p * q;
    phin = (p - 1) * (q - 1);
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