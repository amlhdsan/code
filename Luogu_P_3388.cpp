#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, m;
int head[N], to[N], nxt[N], e = 0;
int dfn[N], low[N], tot = 0;
stack<int> sk;
bool iff[N];
int sum = 0, ans[N];

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

inline void tarjan(int p, bool flag) {
    dfn[p] = low[p] = ++tot;
    sk.push(p);
    iff[p] = 1;

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v, 0);
            low[p] = min(low[p], low[v]);
            if(low[v] >= dfn[p] && !flag) {
                ans[++sum] = p;
            }
        }
        else if(iff[v]) {
            low[p] = min(low[p], dfn[v]);
        }
    }
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u = read(), v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            tarjan(i, 1);
        }
    }

    writeln(sum);

    for(int i = 1; i <= sum; ++i) {
        write(ans[i]);
        putchar(' ');
    }

    return 0;
}