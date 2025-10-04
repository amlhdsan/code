#include <bits/stdc++.h>

#define N 400010
#define M 100010

using namespace std;

int n, m;
int uu[N], vv[N];
int head[N], nxt[N], to[N], e = 1;
int dfn[N], low[N], tot = 0;
int iff[N];
stack<int> sk;
int bl[N], sum = 0;

vector<int> edges[M];
int fa[M][20];

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

        if(v == pre) {
            continue;
        }

        if(!dfn[v]) {
            tarjan(v, p);
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

inline void addedge(int u, int v) {
    edges[u].push_back(v);
    edges[v].push_back(u);
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

    for(int i = 1; i <= n; ++i) {
        if(bl[vv[i]] != bl[uu[i]]) {
            addedge(bl[uu[i]], bl[vv[i]]);
        }
    }

    

    return 0;
}