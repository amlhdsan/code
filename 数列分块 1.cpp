#include <bits/stdc++.h>

#define int long long
#define N 50000
#define SN 250

using namespace std;

int n;
int a[N];
int tag[SN];
int sn;
int id[N];

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

inline void add(int l, int r, int x) {
    for(int i = l; i <= min(id[l] * sn, r); ++i) {
        a[i] += x;
    }

    if(id[l] != id[r]) {
        for(int i = (id[r] - 1) * sn + 1; i <= r; ++i) {
            a[i] += x;
        }
    }

    for(int i = id[l] + 1; i <= id[r] - 1; ++i) {
        tag[i] += x;
    }
}



signed main() {

    n = read();

    sn = sqrt(n);

    for(int i = 1; i <= n; ++i) {
        id[i] = (i - 1) / sn + 1;
    }

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        int opt, l, r, c;
        opt = read();
        l = read();
        r = read();
        c = read();

        if(opt == 0) {
            add(l, r, c);
        }
        else {
            writeln(a[r] + tag[id[r]]);
        }
    }

    return 0;
}