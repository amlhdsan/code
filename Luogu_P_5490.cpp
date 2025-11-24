#include <bits/stdc++.h>

#define N 1000010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n;

int xxx[N], xx = 0;

int ans = 0;

struct linee {
    int l, r;
    int h;
    int tag;
}line[N];

struct treee {
    int cnt;
    int len;
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

inline bool cmp(linee x, linee y) {
    return x.h < y.h;
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p].cnt += x;
    }
    else {
        if(ql <= mid) {
            mdf(ls, l, mid, ql, qr, x);
        }
        if(qr > mid) {
            mdf(rs, mid + 1, r, ql, qr, x);
        }
    }

    if(tree[p].cnt) {
        tree[p].len = xx[r + 1] - xx[l];
    }
    else {
        if(l == r) {
            tree[p].len = 0;
        }
        else {
            tree[p].len = tree[ls].len + tree[rs].len;
        }
    }
}

int main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;
        x1 = read();
        y1 = read();
        x2 = read();
        y2 = read();
        xxx[++xx] = x1;
        xxx[++xx] = x2;
        line[(i << 2) - 1] = {x1, x2, y1, 1};
        line[i << 2] = {x1, x2, y2, -1};
    }

    sort(line + 1, line + 2 * n + 1, cmp);

    sort(xxx + 1, xxx + xx + 1);
    xx = unique(xxx + 1, xxx + xx + 1) - (xxx + 1);

    for(int i = 1; i <= 2 * n - 1; ++i) {
        int l = lower_bound(xxx + 1, xxx + xx + 1, line[i].l) - xxx;
        int r = lower_bound(xxx + 1, xxx + xx + 1, line[i].r) - xxx;
        mdf(1, 1, xx - 1, l, r - 1, line[i].tag);
        ans += (line[i + 1].h - line[i].h) * tree[1].len;
    }

    writeln(ans);

    return 0;
}