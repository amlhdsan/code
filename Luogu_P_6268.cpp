#include <bits/stdc++.h>

#define N 2000010

using namespace std;

int n, m;
bool iff[1010][1010];
int nxt[N], head[N], to[N], e = 0;

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

inline int dinic() {

}

inline void add_edge(int u, int v) {

}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u, v;
        u = read();
        v = read();

        u += 1;
        v += 1;

        iff[u][v] = iff[v][u] = 1;
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(!iff[i][j]) {
                add_edge(i, j);
            }
        }
    }



    return 0;
}