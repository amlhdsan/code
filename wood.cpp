#include <bits/stdc++.h>

#define N 1000010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

const int mx = 2e9;

int n, k, c;
int a[N];
int b[N];
int tree[N << 2];
int lazy[N << 2];

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

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = b[l];
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
}

inline void pushd(int p, int l, int r) {
    if(lazy[p] != 0) {
        tree[ls] += lazy[p] * (mid - l + 1);
        tree[rs] += lazy[p] * (r - (mid + 1) + 1);
        lazy[ls] += lazy[p];
        lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += x * (r - l + 1);
        lazy[p] += x;
        return;
    }
    pushd(p, l, r);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, x);
    }
    upd(p);
}

inline int qry(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return tree[p];
    }
    pushd(p, l, r);
    int mxx = 0;
    if(ql <= mid) {
        mxx += qry(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        mxx += qry(rs, mid + 1, r, ql, qr);
    }
    return mxx;
}

inline int check(int x) {
    for(int i = 1; i <= n; ++i) {
        b[i] = x - a[i];
    }

    build(1, 1, n);
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        int t = qry(1, 1, n, i, i);
        if(t > 0) {
            mdf(1, 1, n, i, min(n, i + c - 1), -t);
            sum += t;
        }
        if(sum > k) {
            return 0;
        }
    }
    return 1;
}

signed main() {

    n = read();
    k = read();
    c = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    int l = 1, r = 10000000000;
    int ans = 0;
    while(l <= r) {
        // int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    writeln(check(2));
    // writeln()

    writeln(ans);

    return 0;
}