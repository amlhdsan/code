#include <bits/stdc++.h>

#define N 100010
#define MOD 1000000007

using namespace std;

int T;
int n, m, v;

int c[N];

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

// v^{2x} - v^x + v^{x - 1}

inline int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return res % MOD;
}

inline int f(int x) {
    return (qpow(v, 2 * x) % MOD - qpow(v, x) % MOD + qpow(v, x - 1) % MOD) % MOD;
}

inline void work() {
    n = read();
    m = read();
    v = read();

    for(int i = 1; i <= m; ++i) {
        c[i] = read();
        read();
    }
    
    sort(c + 1, c + m + 1);

    
}

int main() {

    // writeln(qpow(2, 10));

    T = read();

    while(T--) {
        work();
    }

    return 0;
}