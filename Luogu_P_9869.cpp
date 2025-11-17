#include <bits/stdc++.h>

#define N 100005

using namespace std;

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

int n, m;
char op[N];
int p1[N], p2[N];
int val[N];
int fa[N], neg[N];

int getf(int x) {
    if (fa[x] == x) return x;
    int f = getf(fa[x]);
    neg[x] ^= neg[fa[x]];
    return fa[x] = f;
}

void merge(int x, int y, int inv) {
    int fx = getf(x), fy = getf(y);
    if (fx == fy) {
        if ((neg[x] ^ neg[y]) != inv) {
            val[fx] = 2;
        }
        return;
    }
    fa[fx] = fy;
    neg[fx] = neg[x] ^ neg[y] ^ inv;
}

void solve() {
    n = read(); m = read();
    
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        neg[i] = 0;
        val[i] = -1;
    }
    
    for (int i = 1; i <= m; i++) {
        char c;
        scanf(" %c", &c);
        op[i] = c;
        if (c == 'T' || c == 'F' || c == 'U') {
            p1[i] = read();
            p2[i] = 0;
        } else {
            p1[i] = read();
            p2[i] = read();
        }
    }
    
    for (int i = m; i >= 1; i--) {
        if (op[i] == 'T') {
            int fx = getf(p1[i]);
            if (val[fx] == -1) val[fx] = neg[p1[i]] ? 1 : 0;
            else if (val[fx] != (neg[p1[i]] ? 1 : 0)) val[fx] = 2;
        } else if (op[i] == 'F') {
            int fx = getf(p1[i]);
            if (val[fx] == -1) val[fx] = neg[p1[i]] ? 0 : 1;
            else if (val[fx] != (neg[p1[i]] ? 0 : 1)) val[fx] = 2;
        } else if (op[i] == 'U') {
            int fx = getf(p1[i]);
            if (val[fx] == -1) val[fx] = 2;
        } else if (op[i] == '+') {
            merge(p1[i], p2[i], 0);
        } else {
            merge(p1[i], p2[i], 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i && val[i] == 2) {
            ans++;
        }
    }
    
    writeln(ans);
}

int main() {
    int c = read(), t = read();
    while (t--) {
        solve();
    }
    return 0;
}