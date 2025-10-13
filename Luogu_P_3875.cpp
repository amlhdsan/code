#include <bits/stdc++.h>

#define N 400010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
using namespace std;

int n;
int xx[N], xxx = 0;

struct linee {
    int l, r;
    int h;
    int tag;
}line[N];

struct treee {
    int cnt;
    int len;
}tree[N];

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

inline bool cmp(linee x, linee y) {
    return x.h < y.h;
}

inline void build(int p, int l, int r) {
    tree[p].cnt = tree[p].len = 0;
    if(l == r) {
        return ;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        int s, d, f, g;
        int x1, y1, x2, y2;
        s = read();
        d = read();
        f = read();
        g = read();
        if(s == f) { // 平行于 y 轴
            x1 = s - 1, x2 = s + 1;
            y1 = min(d, g), y2 = max(d, g);
        }
        else {
            x1 = min(s, f), x2 = max(s, f);
            y1 = d - 1, y2 = d + 1;
        }
        xx[++xxx] = x1, xx[++xxx] = x2;
        line[i * 2 - 1] = {x1, x2, y1, 1};
        line[i * 2] = {x1, x2, y2, -1};
    }

    sort(xx + 1, xx + xxx + 1);

    xxx = unique(xx + 1, xx + xxx + 1) - xx - 1;
    sort(line + 1, line + 2 * n + 1, cmp);

    build(1, 1, xxx - 1);
    return 0;
}