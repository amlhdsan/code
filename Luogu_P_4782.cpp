#include <bits/stdc++.h>

#define N 4000010

using namespace std;

int n, m;
int head[N], nxt[N], to[N], e = 0;
int dfn[N], low[N], tot = 0;
stack<int> sk;
bool iff[N];
int sum = 0;
int bl[N];

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

    if (low[p] == dfn[p]) {
        ++sum;
        int x;
        do {
            x = sk.top();
            sk.pop();
            iff[x] = 0;
            bl[x] = sum;
        } while (x != p);
    }
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int ii, aa, jj, bb;
        ii = read();
        aa = read();
        jj = read();
        bb = read();

        add_edge(ii + (aa ^ 1) * n, jj + bb * n);
        add_edge(jj + (bb ^ 1) * n, ii + aa * n);

    }

    for(int i = 1; i <= n * 2; ++i) {
        if(!dfn[i])
            tarjan(i);
    }

    for(int i = 1; i <= n; ++i) {
        if(bl[i] == bl[i + n]) {
            puts("IMPOSSIBLE");
            return 0;
        }
    }

    puts("POSSIBLE");

    for(int i = 1; i <= n; ++i) {
        write((int)!(bl[i] < bl[i + n]));
        putchar(' ');
    }

    return 0;
}