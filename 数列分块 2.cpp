#include <bits/stdc++.h>

#define int long long
#define N 50010
#define SN 250

using namespace std;

int n;
int a[N];
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

inline void mdf(int l, int r, int x) {

}

inline void qry(int l, int r, int x) {

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
            mdf(l, r, c);
        }
        else {
            qry(l, r, c * c);
        }
    }

    return 0;
}