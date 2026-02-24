#include <bits/stdc++.h>
#define N 1000002

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
    if (x < 0) { putchar('-'); x = -x; }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) { write(x); putchar('\n'); }

int n, q;
int fa[N];

int find(int x) {
    while (fa[x] != x) { fa[x] = fa[fa[x]]; x = fa[x]; }
    return x;
}

struct Cond { int l, r, x; } conds[25001];

int ord[25001];

bool check(int k) {
    for (int i = 1; i <= n + 1; i++) fa[i] = i;
    for (int i = 0; i < k; i++) ord[i] = i;
    sort(ord, ord + k, [](int a, int b) { return conds[a].x > conds[b].x; });

    int i = 0;
    while (i < k) {
        int j = i;
        int cx = conds[ord[i]].x;
        int L = conds[ord[i]].l, R = conds[ord[i]].r;
        while (j < k && conds[ord[j]].x == cx) {
            L = max(L, conds[ord[j]].l);
            R = min(R, conds[ord[j]].r);
            j++;
        }
        if (L > R || find(L) > R) return false;
        for (int t = i; t < j; t++) {
            int p = find(conds[ord[t]].l);
            while (p <= conds[ord[t]].r) {
                fa[p] = p + 1;
                p = find(p + 1);
            }
        }
        i = j;
    }
    return true;
}

int main() {
    n = read(); q = read();
    for (int i = 0; i < q; i++) {
        conds[i].l = read(); conds[i].r = read(); conds[i].x = read();
    }

    if (check(q)) { writeln(0); return 0; }

    int lo = 1, hi = q, ans = q;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) lo = mid + 1;
        else { ans = mid; hi = mid - 1; }
    }
    writeln(ans);
    return 0;
}