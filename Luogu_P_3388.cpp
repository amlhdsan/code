#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, m;
int head[N], to[N], nxt[N], e = 0;

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

inline void add_edge(int u, int v) {
    
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    return 0;
}