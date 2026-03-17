#include <bits/stdc++.h>

#define N 200010
#define int long long

using namespace std;

int n, m;
int a[N], b[N];
int c[N];

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
    m = read();
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    c[0] = 1e18;

    for(int i = 1; i <= n; i++) {
        a[i] = read();
        b[i] = b[i - 1] + read();
        c[i] = min(c[i - 1], a[i] - b[i]);
    }

    while(m--) {
        int x = read(), k = read();
        writeln(b[k] + min(c[k], x));
    }
}

signed main() {

    int c, t;
    c = read();
    t = read();

    while(t--) {
        solve();
    }

    return 0;
}