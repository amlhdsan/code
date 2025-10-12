#include <bits/stdc++.h>

#define N 1000010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)

using namespace std;

int n;
int xx[N], xxx = 0; // 离散化 x

struct linee {
    int l, r;
    int h;
    int tag;
}line[N];

struct treee {
    int cnt, len;
}tree[N << 2];

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

inline bool cmp(linee a, linee b) {
    return a.h < b.h;
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        int a1, b1, a2, b2;
        a1 = read();
        b1 = read();
        a2 = read();
        b2 = read();
        xx[++xxx] = a1;
        xx[++xxx] = a2;
        line[i * 2 - 1] = {a1, a2, b1, 1};
        line[i * 2] = {a1, a2, b2, -1};
    }

    sort(xx + 1, xx + xxx + 1);
    xxx = unique(xx + 1, xx + xxx + 1) - xx - 1;
    sort(line + 1, line + 2 * n + 1, cmp);
    return 0;
}