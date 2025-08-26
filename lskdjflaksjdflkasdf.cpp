#include<bits/stdc++.h>

#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int T;
int n;
ll a[200005], p[200005];
int tree[200005];
int lazy[200005];

inline void upd(int p) {
    tree[p] = max(tree[ls], tree[rs]);
}

inline void pushup(int p) {
    if(lazy[p]) {
        tree[ls] += lazy[p];
        lazy[ls] += lazy[p];
        tree[rs] += lazy[p];
        lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = a[l];
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
}

inline void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += x;
        lazy[p] += x;
        return;
    }

    pushup(p);

    if(ql <= mid) 
        mdf(ls, l, mid, ql, qr, x);
    if(qr > mid) 
        mdf(rs, mid + 1, r, ql, qr, x);

    upd(p);
}

inline int qry(int p, int l, int r, int ql, int qr) {
    
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

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int main() {

    T = read();

    while (T--) {
        n = read();
        for(int i = 1; i <= n; ++i) 
            a[i] = read();
            
        ll op = 0;
        ll mx = LLONG_MIN / 4;

        p[0] = 0;

        for (int i = 1; i <= n; ++i) {
            if (i >= 2) 
                mx = max(mx, p[i - 2]);
            int s = (i % 2 == 0) ? 1 : -1;
            p[i] = p[i - 1] + s * a[i];
            if (p[i] < mx) {
                ll myb = mx - p[i];
                if (i % 2 == 1) {
                    ll d = min(myb, a[i]);
                    a[i] -= d;
                    op += d;
                    p[i] += d;
                } 
                else {
                    ll d = min(myb, a[i - 1]);
                    a[i - 1] -= d;
                    op += d;
                    p[i - 1] += d;
                    p[i] += d;
                }
            }
        }
        writeln(op);
    }
    return 0;
}
