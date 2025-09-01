#include <bits/stdc++.h>
#define int long long
#define int long long

char buf[1 << 20], *p1 = buf, *p2 = buf;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? 0 : *p1++)
#define pc(x) putchar_unlocked(x)

using namespace std;

namespace seg_sum {

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

    const int N = 2e5 + 10;
    int tree[N << 2];
    int lazy[N << 2];
    int siz[N << 2];
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
            tree[p] += 1int * siz[p] * k;
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

    int qry(int p, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return tree[p];
        }
        pushd(p);

        int sum = 0;

        if(ql <= mid) {
            sum += qry(ls, l, mid, ql, qr);
        }
        if(qr > mid) {
            sum += qry(rs, mid + 1, r, ql, qr);
        }

        return sum;
    }

}

namespace seg_sum_and_mul {

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

    const int N = 2e5 + 10;
    int tree[N << 2];
    int multy_lazy[N << 2];
    int add_lazy[N << 2];
    int siz[N << 2];
    int a[N];

    void init() {
        memset(tree, 0, sizeof(tree));
        memset(multy_lazy, 1, sizeof(multy_lazy));
        memset(add_lazy, 0, sizeof(add_lazy));
        memset(siz, 0, sizeof(siz));
        memset(a, 0, sizeof(a));
    }

    void upd(int p) {
        tree[p] = (tree[ls] + tree[rs]) % m;
    }

    void upds(int p) {
        siz[p] = siz[ls] + siz[rs];
    }

    void pushd(int p) {
        tree[ls] = (tree[ls] * multy_lazy[p] + siz[ls] * add_lazy[p]) % m;
        tree[rs] = (tree[rs] * multy_lazy[p] + siz[rs] * add_lazy[p]) % m;

        multy_lazy[ls] *= multy_lazy[p];
        multy_lazy[ls] %= m;

        multy_lazy[rs] *= multy_lazy[p];
        multy_lazy[rs] %= m;

        add_lazy[ls] *= multy_lazy[p];
        add_lazy[ls] += add_lazy[p];
        add_lazy[ls] %= m;

        add_lazy[rs] *= multy_lazy[p];
        add_lazy[rs] += add_lazy[p];
        add_lazy[rs] %= m;

        multy_lazy[p] = 1;
        add_lazy[p] = 0;
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
            tree[p] += 1int * siz[p] * k;
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

    int qry(int p, int l, int r, int ql, int qr) {
        if(ql <= l && r <= qr) {
            return tree[p];
        }
        pushd(p);

        int sum = 0;

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
    char ch = gc();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = gc();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = gc();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        pc('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    pc(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    pc('\n');
}

signed main() {

    return 0;
}