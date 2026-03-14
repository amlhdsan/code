#include <bits/stdc++.h>

#define N 110

using namespace std;

int n;
int a[N][N];
int t[N * N];

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

    memset(t, 0, sizeof t);
    n = read();
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            a[i][j] = read;
            t[a[i][j]] += 1;
        }
    }

    int maxx = -1;

    for(int i = 1; i <= N * N - 1; ++i) {
        maxx = max(maxx, t[a[i][j]]);
    }

    if(maxx <= n * n - n) {
        puts("YES");
    }
    else {
        puts("NO");
    }
}

int main() {

    int T = read();

    while(T--) {
        solve();
    }

    return 0;
}