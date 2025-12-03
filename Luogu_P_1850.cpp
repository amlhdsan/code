#include <bits/stdc++.h>

#define N 2010
#define V 310
#define int long long

using namespace std;

int n, m, vv, ee;
int c[N], d[N];
double k[N];
int dis[V][V];

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

inline void rdin() {
    n = read();
    m = read();
    vv = read();
    ee = read();

    for(int i = 1; i <= n; ++i) {
        c[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        d[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        cin >> k[i];
    }

    for(int i = 1; i <= vv; ++i)
        for(int j = 1; j <= vv; ++j)
            dis[i][j] = 0x3f3f3f3f3f3f3f3f;

    for(int i = 1; i <= ee; ++i) {
        int aj, bj, wj;
        aj = read();
        bj = read();
        wj = read();

        dis[aj][bj] = min(dis[aj][bj], wj);
        dis[bj][aj] = min(dis[bj][aj], wj);
    }

    for(int t = 1; t <= vv; ++t) {
        for(int i = 1; i <= vv; ++i) {
            for(int j = 1; j <= vv; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
            }
        }
    }
    return ;
}

signed main() {

    rdin();


    return 0;
}