#include <bits/stdc++.h>

#define N 30000010

using namespace std;

int n, m;
int a[N];
int dep[N];
bool vis[N];
int head[N], nxt[N], to[N], e = 0;

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

inline void print() {
    for(int i = 1; i <= n; ++i) {
        
    }
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

inline void bfs(int s) {
    queue<int> q;
    dep[s] = 0;
    vis[s] = 1;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if(!vis[v]) {
                vis[v] = 1;
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= m; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
        add_edge(v, u);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if((a[i] & a[j]) == a[j]) {
                add_edge(i, j);
            }
        }
    }

    // dep[0] = -1;

    bfs(1);

    for(int i = 1; i <= n; ++i) {
        writeln(dep[i]);
    }

    return 0;
}