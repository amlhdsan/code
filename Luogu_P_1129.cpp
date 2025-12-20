#include <bits/stdc++.h>

#define N 400000
#define PII pair<int, int>

using namespace std;

int T;
int n;
int s, t;
int now[N], dep[N];
int head[N], to[N], nxt[N], w[N], e = 1;

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

inline void add_edge(int u, int v, int c) {
    nxt[++e] = head[u];
    head[u] = e;
    to[e] = v;
    w[e] = c;

    nxt[++e] = head[v];
    head[v] = e;
    to[e] = u;
    w[e] = 0;
}

inline bool bfs() {
    queue<int> q;
    q.push(s);
    memset(dep, 0, sizeof(dep));
    dep[s] = 0;
    now[s] = head[s];

    while(!q.empty()) {
        int p = q.front();
        q.pop();
        for(int i = head[p]; i; i = nxt[i]) {
            int v = to[i];
            if(dep[v] == 0x3f3f3f3f && w[i] > 0) {
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
        k = dfs(v, min(flow, w[i]));

        if(k) {
            w[i] -= k;
            w[i ^ 1] += k;
        }
        else {
            dep[v] = 0x3f3f3f3f;
        }
    }
    return 0;
}

inline void solve() {
    n = read();

    s = 0;
    t = 401;

    for(int i = 1; i <= n; ++i) {
        add_edge(s, i, 1);
        add_edge(i + n, t, 1);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int tmp = read();
            if(tmp) {
                add_edge(i, j + n, 1);
            }
        }
    }
    
    int ans = 0;

    while(bfs()) {
        ans += dfs(s, 0x7fffffff);
    }

    if(ans >= 0) {
        puts("Yes");
    }
    else {
        puts("No");
    }
}

int main() {

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}