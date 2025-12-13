#include <bits/stdc++.h>

#define N 400010
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

int n, d, k, m, idx;
ll ans;
vector<int> p;
unordered_map<int, int> mp;

struct point {
    int x, num;
    bool operator<(const point &b) const {
        return x < b.x;
    }
} arr[N];

struct sec {
    int l, r, num;
    bool operator<(const sec &b) const {
        if (l != b.l) return l < b.l;
        return r < b.r;
    }
} s[N];

ll tree[N << 2];
ll lazy[N << 2];

inline int up(int a, int b) {
    if (a % b == 0) return a / b;
    return a / b + 1;
}

void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

void pushd(int p, int l, int r) {
    if (lazy[p]) {
        tree[ls] += lazy[p] * (mid - l + 1);
        tree[rs] += lazy[p] * (r - mid);
        lazy[ls] += lazy[p];
        lazy[rs] += lazy[p];
        lazy[p] = 0;
    }
}

void mdf(int p, int l, int r, int ql, int qr, ll k) {
    if (ql <= l && r <= qr) {
        tree[p] += k * (r - l + 1);
        lazy[p] += k;
        return;
    }
    pushd(p, l, r);
    if (ql <= mid) mdf(ls, l, mid, ql, qr, k);
    if (qr > mid) mdf(rs, mid + 1, r, ql, qr, k);
    upd(p);
}

ll qry(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return tree[p];
    pushd(p, l, r);
    ll sum = 0;
    if (ql <= mid) sum += qry(ls, l, mid, ql, qr);
    if (qr > mid) sum += qry(rs, mid + 1, r, ql, qr);
    return sum;
}

int main() {
    n = read();
    d = read();
    k = read();
    
    for (int i = 1; i <= n; i++) {
        arr[i].x = read();
        int h = read();
        arr[i].num = up(h, k);
    }
    
    sort(arr + 1, arr + n + 1);
    
    for (int i = 1; i <= n; i++) {
        p.push_back(max(1ll, (ll)arr[i].x - d));
        p.push_back(arr[i].x + d);
        s[i] = {max(1, arr[i].x - d), arr[i].x + d, arr[i].num};
    }
    
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    
    for (auto x : p) mp[x] = ++idx;
    
    for (int i = 1; i <= n; i++) {
        s[i] = {mp[s[i].l], mp[s[i].r], s[i].num};
        m = max(m, s[i].r);
    }
    
    sort(s + 1, s + n + 1);
    
    for (int i = 1; i <= n; i++) {
        ll cnt = s[i].num - qry(1, 1, m, s[i].l, s[i].r);
        if (cnt <= 0) continue;
        ans += cnt;
        mdf(1, 1, m, s[i].l, s[i].r, cnt);
    }
    
    writeln(ans);
    
    return 0;
}