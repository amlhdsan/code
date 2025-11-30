#include <bits/stdc++.h>

#define N 400

using namespace std;

int T;
int n, m;
int fa[N];
int d[N];
int nxt[N << 2], head[N << 2], to[N << 2], e = 0;
int dp[N][N][N]; // 表示以 i 为根的子树中，有 j 个作为上推，黑点最大值为 k.

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
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
}

inline void dfs(int p, int pre) {
    for(int ee = head[p]; ee; ee = nxt[ee]) {
        int v = to[ee];
        if(v != pre) {
            dfs(v, p);
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    dp[p][i][j] = 
                }   
            }
        }
    }
}

inline void solve() {
    n = read();
    m = read();

    for(int i = 2; i <= n; ++i) {
        fa[i] = read();
        add_edge(fa[i], i);
        add_edge(i, fa[i]);
        ++d[fa[i]];
        ++d[i];
    }

    for(int i = 0; i <= n; ++i) {
        if(d[i] == 1) { // 叶子结点
            dp[i][1][0] = 1;
        }
    }
    
    dfs(1, 0);
}

int main() {

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}