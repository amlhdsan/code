#include <bits/stdc++.h>

#define N 1000010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n;
int xx[N], xxx = 0;

struct node {
    int l, r;
    int h;
    int tag; 
}line[N];

struct treee {
    int cnt, len;
}tree[N * 4];

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

inline bool cmp(node a, node b) {
    return a.h < b.h;
}

inline void build(int p, int l, int r) {
    if(l == r) {
        return;
    }
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

    build(1, 1, xxx - 1);

    int ans = 0;

    for(int i = 1; i <= 2 * n - 1; ++i) {
        int l = lower_bound(xx + 1, xx + xxx + 1, line[i].l) - xx;
        int r = lower_bound(xx + 1, xx + xxx + 1, line[i].r) - xx;
        mdf(1, 1, xxx - 1, l, r - 1, line[i].tag);
        ans += tree[1].len * (line[i + 1].h - line[i].h);
    }

    writeln(ans);

    return 0;
}