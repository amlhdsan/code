#include <bits/stdc++.h>

#define N 200010
#define ll long long
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

inline ll read() {
    ll x = 0, f = 1;
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

int n, m, idx;
ll d, a, ans;
vector<ll> p;
map<ll, int> mp;

struct node {
    ll x, h;
    bool operator<(const node &b) const {
        return x < b.x;
    }
} arr[N];

ll tree[N << 2];
ll lazy[N << 2];

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

ll prn() {
    
}

ll qry(int p, int l, int r, int pos) {
    if (l == r) return tree[p];
    pushd(p, l, r);
    if (pos <= mid) return qry(ls, l, mid, pos);
    return qry(rs, mid + 1, r, pos);
}

int main() {
    n = read();
    d = read();
    a = read();
    
    for (int i = 1; i <= n; i++) {
        arr[i].x = read();
        arr[i].h = read();
    }
    
    sort(arr + 1, arr + n + 1);
    
    for (int i = 1; i <= n; i++) {
        p.push_back(arr[i].x);
        p.push_back(arr[i].x + d);
    }
    
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    
    for (auto x : p) mp[x] = ++idx;
    m = idx;
    
    for (int i = 1; i <= n; i++) {
        ll dmg = qry(1, 1, m, mp[arr[i].x]);
        if (dmg >= arr[i].h) continue;
        
        ll need = (arr[i].h - dmg + a - 1) / a;
        ans += need;
        
        int l = mp[arr[i].x];
        int r = mp[arr[i].x + d];
        mdf(1, 1, m, l, r, need * a);
    }
    
    writeln(ans);
    
    return 0;
}