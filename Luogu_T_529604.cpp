#include <bits/stdc++.h>
#define N 2000050
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define int long long
using namespace std;

int n, q, w;
int a[N];
int lss, rss, d;
int tree[N << 2];
int lazy[N << 2];
int siz[N];
int ww;
int ans;
int lun;
int summ = 0;
int ttt;
int intl, rr, midd;

void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void pushd(int p) {
    tree[ls] += 1int * lazy[p] * siz[ls];
    tree[rs] += 1int * lazy[p] * siz[rs];

    lazy[ls] += lazy[p];
    lazy[rs] += lazy[p];

    lazy[p] = 0;
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    if(l == r) {
        tree[p] = a[l];
        siz[p] = 1;
        return;
    }
    build(ls, l, mid);
    build(rs, mid + 1, r);
    upd(p);
    upds(p);
}

void mdf(int p, int l, int r, int ql, int qr, int x) {
    if(ql <= l && r <= qr) {
        tree[p] += 1int * x * siz[p];
        lazy[p] += x;
        return;
    }
    pushd(p);
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, x);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, x);
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

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch - '0');
        ch = getchar();
    }
    return x * f;
}

int main() {

    cin >> n >> q >> w;

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        summ += a[i];
    }

    build(1, 1, n);

    while(q--) {
        ans = 0;
        lun = 0;
        lss = read();
        rss = read();
        d = read();
        summ += 1int * (rss - lss + 1) * d;
        mdf(1, 1, n, lss, rss, d);
        ww = w;
        while(1) {
            if(ww > summ * (1int << lun)) {
                ans += n;
                ww -= summ * (1int << lun);
                ++lun;
            }
            else {
                intl = 1;
                rr = n;
                while(intl <= rr) {
                    midd = (intl + rr) >> 1;
                    if(1int * qry(1, 1, n, 1, midd) * (1int << lun) >= ww) {
                        rr = midd - 1;
                    }
                    else {
                        intl = midd + 1;
                    }
                }
                ans += intl - 1;
                printf("%d\n", ans);
                break;
            }
        }
    }

    return 0;
}