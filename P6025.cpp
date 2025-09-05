// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
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

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

long long l, r;

long long prexor(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

long long F(long long n) {
    if (n == 0) return 0;
    long long res = prexor(n);
    long long p = 1;
    while (p <= n) {
        long long L = p, R = min(n, 2 * p - 1);
        long long len = R - L + 1;
        if (len & 1) res ^= (2 * p - 1);
        p <<= 1;
    }
    return res;
}

int main() {
    cin >> l >> r;
    writeln(F(r) ^ F(l - 1));
    return 0;
}
