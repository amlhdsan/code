#include <bits/stdc++.h>
using namespace std;

namespace seg {

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define ll long long

    const int N = 2e5 + 10;
    int tree[N];
    int lazy[N];
    int siz[N];
    int a[N];

    void init() {
        memset(tree, 0, sizeof(tree));
        memset(lazy, 0, sizeof(lazy));
        memset(siz, 0, sizeof(siz));
        memset(a, 0, sizeof(a));
    }

    void upd(int p) {
        tree[p] = tree[ls] + tree[rs];
    }

    void upds(int p) {
        siz[p] = siz[ls] + siz[rs];
    }

    void pushd(int p) {
        tree[ls] += lazy[p] * siz[ls];
        tree[rs] += lazy[p] * siz[rs];

        lazy[ls] += lazy[p];
        lazy[rs] += lazy[p];

        lazy[p] = 0;
    }

    void build(int p, int l, int r) {
        lazy[p] = 0;
        if(l == r)  {
            siz[p] = 1;
            tree[p] = a[l];
            return ;
        }
        build(ls, l, mid);
        build(rs, mid + 1, r);
        upd(p);
        upds(p);
    }

    void mdf(int p, int l, int r, int ql, int qr, int k) {
        if(ql <= l && r <= qr) {
            tree[p] += 1ll * siz[p] * k;
            lazy[p] += k;
            return;
        }
        pushd(p);
        if(ql <= mid) {
            mdf(ls, l, mid, ql, qr, k);
        }
        if(qr > mid) {
            mdf(rs, mid + 1, r, ql, qr, k);
        }
        upd(p);
    }

    ll qry(int p, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return tree[p];
        }
        pushd(p);

        ll sum = 0;

        if(ql <= mid) {
            sum += qry(ls, l, mid, ql, qr);
        }
        if(qr > mid) {
            sum += qry(rs, mid + 1, r, ql, qr);
        }

        return sum;
    }

}

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

int main() {

    seg::init();

    int n = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        seg::a[i] = x;
    }
    seg::build(1, 1, n);

    int m = read();
    while (m--) {
        int op = read();
        if (op == 1) {
            int l = read(), r = read(), k = read();
            seg::mdf(1, 1, n, l, r, k);
        } 
        else {
            int l = read(), r = read();
            writeln(seg::qry(1, 1, n, l, r));
        }
    }

    return 0;
}