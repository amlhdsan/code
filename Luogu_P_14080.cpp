#include <bits/stdc++.h>

#define N 1000010
#define ll long long

using namespace std;

int n, m;
int ww[N], fa[N], dep[N], ans[N], f[N], re[N];
ll mi;
bool fl[N];

int s, t;

inline void dfs(int p, int pre) {
    
}

struct node {
    int u, v, w, id;
};

vector<node> e, g;
vector<pair<int, int>> G[N];

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

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void dfs(int x, int p) {
    f[x] = p;
    dep[x] = dep[p] + 1;
    for (auto i : G[x]) {
        if (i.first == p) continue;
        re[i.second] = i.first;
        dfs(i.first, x);
    }
}

bool cmp(node a, node b) {
    return a.w < b.w;
}

int main() {
    n = read(), m = read();
    
    for (int i = 1; i <= n; ++i) fa[i] = i;
    
    for (int i = 1; i <= m; ++i) {
        int u = read(), v = read(), w = read();
        ww[i] = w;
        e.push_back({u, v, w, i});
    }

    sort(e.begin(), e.end(), cmp);

    for (int i = 0; i < m; ++i) {
        int x = find(e[i].u), y = find(e[i].v);
        if (x == y) {
            g.push_back(e[i]);
            continue;
        }
        fl[e[i].id] = 1;
        G[e[i].u].push_back({e[i].v, e[i].id});
        G[e[i].v].push_back({e[i].u, e[i].id});
        mi += e[i].w;
        fa[x] = y;
    }
    
    for (int i = 2; i <= n; ++i) {
        if (find(i) != find(1)) {
            for (int j = 1; j <= m; ++j) writeln(-1);
            return 0;
        }
    }
    
    dfs(1, 0);
    
    for (int i = 1; i <= n; ++i) ans[i] = -1, fa[i] = i;
    
    for (auto i : g) {
        int u = find(i.u), v = find(i.v), w = i.w;
        while (u != v) {
            if (dep[u] < dep[v]) swap(u, v);
            ans[u] = w;
            fa[u] = find(f[u]);
            u = find(u);
        }
    }
    
    for (int i = 1; i <= m; ++i) {
        if (fl[i]) {
            if (ans[re[i]] == -1) writeln(-1);
            else writeln(mi - ww[i] + ans[re[i]]);
        } else writeln(mi);
    }
    
    return 0;
}