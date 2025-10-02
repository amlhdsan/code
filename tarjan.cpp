#include <bits/stdc++.h>

#define M 200010
#define N 200010

using namespace std;

int n, m;
int head[M], to[M], e = 0, nxt[M];
int dfn[N], low[N];
int cnt = 0;
int sum = 0;
int sk[N], top = 0, insk[N];
vector<int> bl[N];
int ans[N];

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

inline void dfs(int p) {
    dfn[p] = low[p] = ++cnt;
    sk[++top] = p, insk[p] = 1;

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            dfs(v);
            low[p] = min(low[p], low[v]);
        }
        else if(insk[v]) {
            low[p] = min(low[p], low[v]);
        }
    }

    if(low[p] == dfn[p]) {
        ++sum;
        bl[sum].push_back(p);

        while(sk[top] != p) {
            ans[sk[top]] = sum;
            insk[sk[top]] = 0;
            bl[sum].push_back(s[top]);
            --top;
        }

        --top;
        insk[p] = 0;
        ans[p] = sum;
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
    }

    for(int i = 1; i <= n; ++i) {
        if(!dfn[i]) {
            dfs(i);
        }
    }

    writeln(sum);

    for(int i = 1; i <= sum; ++i) {
        sort(bl[i].begin(), bl[i].end());
    }

    for(int i = 1; i <= n; ++i) {
        for(int t : bl[ans[i]]) {
            write(t);
            putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}