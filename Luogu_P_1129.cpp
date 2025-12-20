#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int T;
int n;
int a[210][210];
int head[N], nxt[N], to[N], w[N], e = 0;

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

inline void solve() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            a[i][j] = read();
        }
    }
}

int main() {

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}