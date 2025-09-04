#include <bits/stdc++.h>

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)
#define N 100010

using namespace std;

int n, m;
int tree[N << 2], siz[N << 2], lazy[N << 2];

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

inline void upd(int p) {
    tree[p] = tree[ls] + tree[rs];
}

inline void upds(int p) {
    siz[p] = siz[ls] + siz[rs];
}

inline void pushd(int p) {
    
}

inline void build(int p, int l, int r) {
    if(l == r) {
        tree[p] = l;
        lazy[p] = 0;
        siz[p] = 1;
        return;
    }

    build(ls, l, mid);
    build(rs, mid + 1, r);

    upd(p);
    upds(p);
}

int main() {

    n = read();
    m = read();

    while(m--) {
        int op, l, r, k;
        op = read();
        if(op == 1) {
            l = read();
            r = read();
            k = read();
            mdf(1, 1, n, l, r, k);
        }
        else {
            l = read();
            r = read();
            writeln(1, 1, n, l, r);
        }
    }

    return 0;
}