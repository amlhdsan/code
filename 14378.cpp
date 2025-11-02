#include <bits/stdc++.h>

#define N 1000010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define PII pair<int, int>

using namespace std;

int n, k, q;
int a[N], a0[N];
int c[N], cnttt = 0;
int tmpb[N], tmpc[N];

PII tree1[N << 2], tree2[N << 2], tree3[N << 2]; // first:max second:min

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

inline bool cmp(int x, int y) {
    return x > y;
}

inline void upd1(int p) {
    tree1[p].first = max(tree1[ls].first, tree1[rs].first);
    tree1[p].second = min(tree1[ls].second, tree1[rs].second);
}

inline void upd2(int p) {
    tree2[p].first = max(tree2[ls].first, tree2[rs].first);
    tree2[p].second = min(tree2[ls].second, tree2[rs].second);
}

inline void upd3(int p) {
    tree3[p].first = max(tree3[ls].first, tree3[rs].first);
    tree3[p].second = min(tree3[ls].second, tree3[rs].second);
}

inline void build1(int p, int l, int r) {
    if(l == r) {
        tree1[p] = {a[l] + c[l], a[l] + c[l]};
        return;
    }
    build1(ls, l, mid);
    build1(rs, mid + 1, r);
    upd1(p);
}

inline void build2(int p, int l, int r) {
    if(l == r) {
        tree2[p] = {a[l - 1] + c[l], a[l - 1] + c[l]};
    }
    build2(ls, l, mid);
    build2(rs, mid + 1, r);
    upd2(p);
}

inline void build3(int p, int l, int r) {
    if(l == r) {
        tree3[p] = {a[l + 1] + c[l], a[l + 1] + c[l]};
    }
    build3(ls, l, mid);
    build3(rs, mid + 1, r);
    upd3(p);
}

int main() {

    n = read();
    k = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        a0[i] = a[i];
    }

    for(int i = 1; i <= k; ++i) {
        tmpb[i] = read();
    }

    for(int i = 1; i <= k; ++i) {
        tmpc[i] = read();
    }

    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= tmpb[i]; ++j)
            c[++cnttt] = tmpc[i];
    }

    sort(c + 1, c + n + 1, cmp);

    sort(a + 1, a + n + 1);

    build1(1, 1, n);
    build2(1, 1, n);
    build3(1, 1, n);

    while(q--) {
        int xi, vi;
        xi = read();
        vi = read();
        int xx = a[xi];
        if(vi == xx) {
            writeln(tree1[1].first - tree1[1].second);
        }
        else if(vi > xx) {
            int pos = lower_bound(a + 1, a + n + 1, vi, cmp) - a;
            if(pos > n) {
                writeln(tree2[1].first - tree2[1].second);
            }
            else {
                int nmax = max(tree2[1].first, c[pos]);
                int nmin = min(tree2[1].second, c[pos]);
                writeln(nmax - nmin);
            }
        }
        else {
            int pos = upper_bound(c + 1, c + n + 1, vi, cmp) - c - 1;
            if(pos < 1) {
                writeln(tree3[1].first - tree3[1].second);
            }
            else {
                int nmax = max(tree3[1].first, c[pos]);
                int nmin = min(tree3[1].second, c[pos]);
                writeln(nmax - nmin);
            }
        }
    }

    return 0;
}