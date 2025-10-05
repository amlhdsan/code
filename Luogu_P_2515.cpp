#include <bits/stdc++.h>
using namespace std;

int n, m;
int W[110], V[110], D[110];
int head[1010], nxt[1010], to[1010], e = 0;

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
    
    for(int i = 1; i <= n; ++i) {
        W[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        V[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        D[i] = read();
    }



    return 0;
}