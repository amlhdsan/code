#include <bits/stdc++.h>

#define N 16010

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

inline void push() {
    
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int n, m;
vector<int> g[N];
int dfn[N], low[N], scc[N], stk[N], ins[N];
int tim, top, cnt;
int ans[N];

int other(int x) {
    if(x & 1) return x + 1;
    return x - 1;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    stk[++top] = u;
    ins[u] = 1;
    
    for(int v : g[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    
    if(dfn[u] == low[u]) {
        cnt++;
        int v;
        do {
            v = stk[top--];
            ins[v] = 0;
            scc[v] = cnt;
        } while(v != u);
    }
}

int main() {
    n = read();
    m = read();
    
    for(int i = 1; i <= m; ++i) {
        int a = read(), b = read();
        g[a].push_back(other(b));
        g[b].push_back(other(a));
    }
    
    for(int i = 1; i <= 2 * n; ++i) {
        if(!dfn[i]) {
            tarjan(i);
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        int a = 2 * i - 1, b = 2 * i;
        if(scc[a] == scc[b]) {
            printf("NIE\n");
            return 0;
        }
        if(scc[a] < scc[b]) {
            ans[i] = a;
        }
        else {
            ans[i] = b;
        }
    }
    
    sort(ans + 1, ans + n + 1);
    
    for(int i = 1; i <= n; ++i) {
        writeln(ans[i]);
    }
    
    return 0;
}