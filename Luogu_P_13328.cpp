#include <bits/stdc++.h>

#define N 1010

using namespace std;

int T;
int n;

struct node {
    int l, p;
    int ind;
}a[N];

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

inline bool cmp(node x, node y) {
    return x.p * y.l == x.l * y.p ? x.ind < y.ind : x.p * y.l > x.l * y.p;
}

inline bool cmp2(node x, node y) {
    
}

int main() {

    T = read();
    
    for(int t = 1; t <= T; ++t) {
        n = read();

        for(int i = 1; i <= n; ++i) {
            a[i].l = read();
            a[i].ind = i;
        }

        for(int i = 1; i <= n; ++i) {
            a[i].p = read();
        }

        sort(a + 1, a + n + 1, cmp);

        printf("Case #%d:", t);

        for(int i = 1; i <= n; ++i) {
            putchar(' ');
            write(a[i].ind - 1);
        }

        putchar('\n');
    }

    return 0;
}