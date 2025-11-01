#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m, s;
int head[N], to[N], nxt[N], e = 0;
int lg[N];
int fa[N][31];
int dep[N];

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
    fa[p][0] = pre;
    dep[p] = dep[pre] + 1;
    for(int i = 1; i <= lg[dep[p]]; ++i) {
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(v != pre) {
            dfs(v, p);
        }
    }
}

inline int lca(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }

    while(dep[u] > dep[v]) {
        u = fa[u][lg[dep[u] - dep[v]] - 1];
    }

    if(u == v) {
        return u;
    }

    for(int i = lg[dep[u]] - 1; i >= 0; --i) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }

    return fa[u][0];
}

int main() {

    n = read();
    m = read();
    s = read();

    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        u = read();
        v = read();

        add_edge(u, v);
        add_edge(v, u);
    }

    int cntt = 0;

    for(int i = 1; i <= n; ++i) {
        if(i >= (1 << cntt)) {
            ++cntt;
            lg[i] = cntt;
        }
        else {
            lg[i] = cntt;
        }
    }

    dfs(s, 0);

    while(m--) {
        int u, v;
        u = read();
        v = read();

        writeln(lca(u, v));
    }

    return 0;
}