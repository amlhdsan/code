#include <bits/stdc++.h>

#define N 400010
#define M 100010

using namespace std;

int n, m;
int uu[N], vv[N];
int head[N], nxt[N], to[N], e = 1;
int dfn[N], low[N], tot = 0;
stack<int> sk;
int bl[N], sum = 0;

vector<int> edges[M];
int fa[M][21];
int dep[M];

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

inline void tarjan(int p, int pre) {
    dfn[p] = low[p] = ++tot;
    sk.push(p);

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];

        if(i == (pre ^ 1)) 
            continue;

        if(!dfn[v]) {
            tarjan(v, i);
            low[p] = min(low[p], low[v]);
        }
        else {
            low[p] = min(low[p], dfn[v]);
        }
    }

    if(dfn[p] == low[p]) {
        ++sum;
        bl[p] = sum;
        while(sk.top() != p) {
            bl[sk.top()] = sum;
            sk.pop();
        }
        sk.pop();
    }
}

inline void dfs(int p, int pre) {
    dep[p] = dep[pre] + 1;
    fa[p][0] = pre;

    for(int i = 1; i <= 20; ++i) {
        fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }

    for(int v : edges[p]) {
        if(v != pre && !dep[v]) {
            dfs(v, p);
        }
    }
}

inline void faster() {
    
}

inline int lca(int u, int v) {
    if(dep[u] < dep[v]) {
        swap(u, v);
    }

    for(int i = 20; i >= 0; --i) {
        if(dep[v] <= dep[u] - (1 << i)) {
            u = fa[u][i];
        }
    }

    if(u == v) {
        return u;
    }

    for(int i = 20; i >= 0; --i) {
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

    for(int i = 1; i <= m; ++i) {
        uu[i] = read();
        vv[i] = read();
        
        add_edge(uu[i], vv[i]);
        add_edge(vv[i], uu[i]);
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            tarjan(i, 0);
        }
    }

    set<pair<int,int>> st;
    for(int i = 1; i <= m; ++i) {
        int u = bl[uu[i]];
        int v = bl[vv[i]];
        if(u != v) {
            if(u > v) swap(u, v);
            if(st.find({u, v}) == st.end()) {
                st.insert({u, v});
                edges[u].push_back(v);
                edges[v].push_back(u);
            }
        }
    }

    for(int i = 1; i <= sum; ++i) {
        if(!dep[i]) {
            dfs(i, 0);
        }
    }

    int q = read();

    while(q--) {
        int u, v;
        u = read();
        v = read();
        u = bl[u];
        v = bl[v];
        writeln(dep[u] + dep[v] - 2 * dep[lca(u, v)]);
    }

    return 0;
}