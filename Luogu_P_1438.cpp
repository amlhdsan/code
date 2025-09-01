#include <bits/stdc++.h>

#define N 100001
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, m;
int a[N];
int opt;
int intl, rr, kk, dd, pp;
int tree[N << 2];
int siz[N << 2];
int lazy[N << 2];

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

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    for(int i = n; i >= 2; --i) {
        a[i] = a[i] - a[i - 1];
    }

    build(1, 1, n);

    while(m--) {
        cin >> opt;
        if(opt == 1) {
            cin >> intl >> rr >> kk >> dd;
            mdf(1, 1, n, intl, intl, kk);
            if(intl + 1 <= rr)
                mdf(1, 1, n, intl + 1, rr, dd);
            if(rr + 1 <= n)
                mdf(1, 1, n, rr + 1, rr + 1, - (kk + dd * (rr - intl)));
        }
        else {
            cin >> pp;
            cout << qry(1, 1, n, 1, pp) << endl;
        }
    }

    return 0;
}