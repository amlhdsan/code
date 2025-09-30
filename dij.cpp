#include <bits/stdc++.h>
using namespace std;

int n, m;
int nxt[100010], head[100010], e = 0, to[100010], w[100010];
int dis[100010];
bool vis[100010];

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

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) dis[i] = INT_MAX;
    dis[1] = 0;

    return 0;
}