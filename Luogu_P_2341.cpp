#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m;
int head[N], nxt[N], to[N], e = 0;
int dfn[N], low[N], tot = 0;
stack<int> sk;
bool iff[N];
int cnt = 0;
int bl[N];
int sum[N];
int dg[N];

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
    dfn[p] = low[p] = ++tot;
    sk.push(p);
    iff[p] = 1;

    for(int i = head[p]; i; i = nxt[i]) {
        int v = to[i];
        if(!dfn[v]) {
            tarjan(v);
            low[p] = min(low[p], low[v]);
        }
        else if(iff[v]) {
            low[p] = min(low[p], dfn[v]);
        }
    }

    int tmp;

    if(low[p] == dfn[p]) {
        ++cnt;
        do {
            tmp = sk.top();
            sk.pop();
            iff[tmp] = 0;
            bl[tmp] = cnt;
            ++sum[cnt];
        } while(tmp != p);
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
            tarjan(i);
        }
    }

    for(int p = 1; p <= n; ++p) {
        for(int i = head[p]; i; i = nxt[i]) {
            int v = to[i];
            if(bl[p] != bl[v]) {
                ++dg[bl[p]];
            }
        }
    }

    int index = 0;

    for(int i = 1; i <= cnt; ++i) {
        if(dg[i] == 0) {
            if(index != 0) {
                writeln(0);
                return 0;
            }
            index = i;
        }
    }

    writeln(sum[index]);

    return 0;
}