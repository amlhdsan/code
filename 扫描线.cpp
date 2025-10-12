// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;
#define ls(x) (x<<1)
#define rs(x) (x<<1|1)
typedef long long ll;

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

const int N = 200005;
const int M = N << 2;

int n;
int xx1, yy1, xx2, yy2;

struct Line {
    int lx, rx, y, tag;
} l[N << 1];

int X[N << 1], totx = 0;

struct Node {
    int l, r, cnt, len;
} tr[M];

bool cmp(Line a, Line b) {
    return a.y < b.y;
}

void build(int p, int l, int r) {
    tr[p].l = l;
    tr[p].r = r;
    tr[p].cnt = 0;
    tr[p].len = 0;
    if (l == r) return;
    int mid = l + r >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
}

void upd(int p) {
    if (tr[p].cnt) tr[p].len = X[tr[p].r + 1] - X[tr[p].l];
    else {
        if (tr[p].l == tr[p].r) tr[p].len = 0;
        else tr[p].len = tr[ls(p)].len + tr[rs(p)].len;
    }
}

void change(int p, int l, int r, int ad) {
    if (l <= tr[p].l && tr[p].r <= r) tr[p].cnt += ad;
    else {
        if (l <= tr[ls(p)].r) change(ls(p), l, r, ad);
        if (tr[rs(p)].l <= r) change(rs(p), l, r, ad);
    }
    upd(p);
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        xx1 = read();
        yy1 = read();
        xx2 = read();
        yy2 = read();
        X[++totx] = xx1;
        X[++totx] = xx2;
        l[(i << 1) - 1] = {xx1, xx2, yy1, 1};
        l[i << 1] = {xx1, xx2, yy2, -1};
    }

    sort(X + 1, X + totx + 1);
    totx = unique(X + 1, X + totx + 1) - X - 1;
    sort(l + 1, l + (n << 1) + 1, cmp);
    build(1, 1, totx - 1);

    ll ans = 0;
    for (int i = 1; i < (n << 1); i++) {
        int lft = lower_bound(X + 1, X + totx + 1, l[i].lx) - X;
        int rig = lower_bound(X + 1, X + totx + 1, l[i].rx) - X;
        change(1, lft, rig - 1, l[i].tag);
        ans += 1ll * tr[1].len * (l[i + 1].y - l[i].y);
    }

    write(ans);
    return 0;
}
