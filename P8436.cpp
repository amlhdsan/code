#include <bits/stdc++.h>

#define N 4000010

using namespace std;

int n, m;
int head[N], nxt[N], to[N], e = 0;
int dfn[N], low[N], cnt = 0;
stack<int> st;
int dcc[N];
bool iff[N];
vector<vector<int>> ans;
int sum = 0;

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
    dfn[p] = low[p] = ++cnt;
    st.push(p);

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v, i);
            if(dfn[p] < low[v]) {
                iff[i] = iff[i ^ 1] = 1;
            }
            low[p] = min(low[p], low[v]);
        }
        else if(i != (pre ^ 1)) {
            low[p] = min(low[p], dfn[v]);
        }
    }
}

inline void dfs(int p) {
    dcc[p] = sum;
    ans[sum - 1].push_back(p);
    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(!(dcc[v] || d[i])) {
            dfs(v);
        }
    }
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            tarjan(i, 0);
        }
    }

    for(int i = 1; i <= n; ++i) {
        if(!dcc[i]) {
            ans.emplace_back();
            ++sum;
            dfs(i);
        }
    }

    writeln(sum);
    for(int i = 0; i < sum; ++i) {
        write(ans[i].size());
        for(int j : ans[i]) {
            putchar(' ');
            write(j);
        }
        putchar('\n');
    }
    return 0;
}