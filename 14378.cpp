#include <bits/stdc++.h>

#define N 1000010
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

int n, k, q;
int a[N];
int c[N], cnttt = 0;
int tmpb[N], tmpc[N];

int tree1[N << 2], tree2[N << 2], tree3[N << 2];

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

inline void build1(int p, int l, int r) {
    if(l == r) {
        tree1[p] = a[l];
        return;
    }
    build1(ls, l, mid);
    build1(rs, mid + 1, r);
}

inline void build2(int p, int l, int r) {
    if(l == r) {
        tree2[p] = a[l - 1];
    }
    build2(ls, l, mid);
    build2(rs, mid + 1, r);
}

inline void build3(int p, int l, int r) {
    if(l == r) {
        tree3[p] = a[l + 1];
    }
    build3(ls, l, mid);
    build3(rs, mid + 1, r);
}

int main() {

    n = read();
    k = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
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

    return 0;
}