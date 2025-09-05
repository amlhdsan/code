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

const int N = 100005;

int n, m;
long long b1[N], b2[N];

inline void add(long long *b, int x, long long v) {
    while (x <= n) {
        b[x] += v;
        x += x & -x;
    }
}

inline long long sum(long long *b, int x) {
    long long res = 0;
    while (x) {
        res += b[x];
        x -= x & -x;
    }
    return res;
}

inline void range_add(int l, int r, long long v) {
    add(b1, l, v);
    add(b1, r + 1, -v);
    add(b2, l, v * (l - 1));
    add(b2, r + 1, -v * r);
}

inline long long prefix(int x) {
    return (long long)(x + 1) * sum(b1, x) - sum(b2, x);
}

inline long long query(int l, int r) {
    long long base = 1ll * (l + r) * (r - l + 1) / 2;
    return base + (prefix(r) - prefix(l - 1));
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) {
        int op = read();
        if (op == 1
        ) {
            int l = read(), r = read(), k = read();
            range_add(l, r, k);
        } else {
            int l = read(), r = read();
            writeln(query(l, r));
        }
    }
    return 0;
}
