#include <bits/stdc++.h>

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define N 1000010
#define int long long

using namespace std;

int n;
int ans = 0;

int xxx[N], xx = 0;

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

inline bool cmp(linee x, linee y) {
    return x.h < y.h;
}

inline void build(int p, int l, int r) {
    tree[p].cnt = 0;
    tree[p].len = 0;
    build(ls, l, mid);
    build(rs, mid + 1, r);
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
        tree[p].len = xxx[r + 1] - xxx[l];
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

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        int a, b, c, d;
        a = read();
        b = read();
        c = read();
        d = read();

        line[(i << 1) - 1] = {a, c, b, 1};
        line[(i << 1)] = {a, c, d, -1};

        xxx[++xx] = a;
        xxx[++xx] = c;
    }

    sort(line + 1, line + 2 * n + 1, cmp);
    sort(xxx + 1, xxx + xx + 1);
    xx = unique(xxx + 1, xxx + xx + 1) - (xxx + 1);

    build(1, 1, xx - 1);

    for(int i = 1; i <= n * 2 - 1; ++i) {
        int l = lower_bound(xxx + 1, xxx + xx + 1, line[i].l) - xxx;
        int r = lower_bound(xxx + 1, xxx + xx + 1, line[i].r) - xxx;

        mdf(1, 1, xx - 1, l, r - 1, line[i].tag);

        ans += tree[1].len * (line[i + 1].h - line[i].h);
    }

    writeln(ans);

    return 0;
}