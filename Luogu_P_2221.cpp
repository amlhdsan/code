#include <bits/stdc++.h>

#define N 100007
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

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

int n, m;
ll sum1[N << 2], sum2[N << 2], sum3[N << 2];
ll idx[N << 2], idx2[N << 2];
ll lazy[N << 2];

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

void upd1(int p) {
    sum1[p] = sum1[ls] + sum1[rs];
}

void upd2(int p) {
    sum2[p] = sum2[ls] + sum2[rs];
}

void upd3(int p) {
    sum3[p] = sum3[ls] + sum3[rs];
}

void pushd(int p, int l, int r) {
    ll k = lazy[p];
    ll len1 = mid - l + 1;
    ll len2 = r - mid;
    
    sum1[ls] += len1 * k;
    sum1[rs] += len2 * k;
    
    sum2[ls] += k * idx[ls];
    sum2[rs] += k * idx[rs];
    
    sum3[ls] += k * idx2[ls];
    sum3[rs] += k * idx2[rs];
    
    lazy[ls] += k;
    lazy[rs] += k;
    
    lazy[p] = 0;
}

void build(int p, int l, int r) {
    lazy[p] = 0;
    
    if(l == r) {
        sum1[p] = 0;
        sum2[p] = 0;
        sum3[p] = 0;
        idx[p] = l;
        idx2[p] = 1ll * l * l;
        return;
    }
    
    build(ls, l, mid);
    build(rs, mid + 1, r);
    
    upd1(p);
    upd2(p);
    upd3(p);
    idx[p] = idx[ls] + idx[rs];
    idx2[p] = idx2[ls] + idx2[rs];
}

void mdf(int p, int l, int r, int ql, int qr, ll k) {
    if(ql <= l && r <= qr) {
        sum1[p] += 1ll * (r - l + 1) * k;
        sum2[p] += k * idx[p];
        sum3[p] += k * idx2[p];
        lazy[p] += k;
        return;
    }
    
    pushd(p, l, r);
    
    if(ql <= mid) {
        mdf(ls, l, mid, ql, qr, k);
    }
    if(qr > mid) {
        mdf(rs, mid + 1, r, ql, qr, k);
    }
    
    upd1(p);
    upd2(p);
    upd3(p);
}

ll qry1(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return sum1[p];
    }
    
    pushd(p, l, r);
    
    ll res = 0;
    
    if(ql <= mid) {
        res += qry1(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        res += qry1(rs, mid + 1, r, ql, qr);
    }
    
    return res;
}

ll qry2(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return sum2[p];
    }
    
    pushd(p, l, r);
    
    ll res = 0;
    
    if(ql <= mid) {
        res += qry2(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        res += qry2(rs, mid + 1, r, ql, qr);
    }
    
    return res;
}

ll qry3(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        return sum3[p];
    }
    
    pushd(p, l, r);
    
    ll res = 0;
    
    if(ql <= mid) {
        res += qry3(ls, l, mid, ql, qr);
    }
    if(qr > mid) {
        res += qry3(rs, mid + 1, r, ql, qr);
    }
    
    return res;
}

int main() {
    n = read();
    m = read();
    
    build(1, 1, n);
    
    while(m--) {
        char op[3];
        scanf("%s", op);
        
        int l = read();
        int r = read() - 1;
        
        if(op[0] == 'C') {
            ll v = read();
            mdf(1, 1, n, l, r, v);
        }
        else {
            ll s1 = qry1(1, 1, n, l, r);
            ll s2 = qry2(1, 1, n, l, r);
            ll s3 = qry3(1, 1, n, l, r);
            
            ll a = (r - l + 1 - 1ll * r * l) * s1 + (r + l) * s2 - s3;
            ll b = 1ll * (r - l + 2) * (r - l + 1) / 2;
            
            ll g = gcd(a, b);
            
            printf("%lld/%lld\n", a / g, b / g);
        }
    }
    
    return 0;
}