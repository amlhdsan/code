// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
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

const int N = 200005;
int n, q;
int t[N << 2];

void upd(int p, int l, int r, int x, int v) {
    if (l == r) {
        t[p] = v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) upd(p << 1, l, mid, x, v);
    else upd(p << 1 | 1, mid + 1, r, x, v);
    t[p] = min(t[p << 1], t[p << 1 | 1]);
}

int qry(int p, int l, int r, int L, int R) {
    if (L <= l && r <= R) return t[p];
    int mid = (l + r) >> 1, res = 1;
    if (L <= mid) res = min(res, qry(p << 1, l, mid, L, R));
    if (R > mid) res = min(res, qry(p << 1 | 1, mid + 1, r, L, R));
    return res;
}

int main() {
    n = read(), q = read();
    for (int i = 1; i <= q; i++) {
        char op;
        cin >> op;
        if (op == '-') {
            int a = read();
            upd(1, 1, n, a, 1);
        } else if (op == '+') {
            int a = read();
            upd(1, 1, n, a, 0);
        } else {
            int a = read(), b = read();
            int ok = 0;
            if (a == b) ok = 1;
            else if (a < b) ok = (qry(1, 1, n, a, b - 1) == 0);
            else ok = (qry(1, 1, n, a, n) == 0 && qry(1, 1, n, 1, b - 1) == 0);
            if (ok) printf("possible\n");
            else printf("impossible\n");
        }
    }
    return 0;
}
