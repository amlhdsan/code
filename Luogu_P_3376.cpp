#include <bits/stdc++.h>

#define int long long
#define N 100010

using namespace std;

int n, m, s, t;
int head[N], to[N], nxt[N], w[N], e = 1
;
int now[N]; // 当前弧优化
int dep[N];

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

inline void add(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    w[e] = c;
}

inline bool bfs() {
    queue<int> q;
    q.push(s);
    memset(dep, 0x3f, sizeof(dep));
    dep[s] = 0;
    now[s] = head[s];

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int i = head[p]; i; i = nxt[i]) {
            int v = to[i];
            if(dep[v] >= 10000000 && w[i] > 0) {
                dep[v] = dep[p] + 1;
                now[v] = head[v];
                q.push(v);
                if(v == t) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

inline int dfs(int p, int flow) {
    if(p == t) {
        return flow;
    }
    int k;
    for(int i = now[p]; i; i = nxt[i]) {
        now[p] = i;
        int v = to[i];
        if(dep[v] != dep[p] + 1 || w[i] <= 0) {
            continue;
        }
        k = dfs(v, min(w[i], flow));

        if(k) {
            w[i] -= k;
            w[i ^ 1] += k;
            return k;
        }

        else {
            dep[v] = 0x3f3f3f3f3f3f3f3f - 1000000;
        }
    }
    return 0;
}

inline int dinic() {
    int ret = 0;
    while(bfs()) {
        ret += dfs(s, 0x3f3f3f3f3f3f3f3f);
    }

    return ret;
}

signed main() {

    n = read();
    m = read();
    s = read();
    t = read();

    while(m--) {
        int u, v, c;
        u = read();
        v = read();
        c = read();

        add(u, v, c);
        add(v, u, 0);
    }

    writeln(dinic());

    return 0;
}