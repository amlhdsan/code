#include <bits/stdc++.h>

#define N 4000010

using namespace std;

int n, m;
int head[N], nxt[N], to[N], e = 0;
int dfn[N], low[N], cnt = 0;
stack<int> st;

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

inline void tarjan(int p) {
    dfn[p] = low[p] = ++cnt;
    st.push(p);

    for(int i = head[p]; i; i = nxt[i]) {
        if()
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
            tarjan(i);
        }
    }

    return 0;
}