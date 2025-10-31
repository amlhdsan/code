#include <bits/stdc++.h>

#define N 1000010
#define int long long
#define PII pair<int, int>

using namespace std;

int n, m, s;
int dis[N];
bool vis[N];
int head[N], nxt[N], to[N], w[N], e = 0;

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
}

inline void dijsktra() {
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push(make_pair(0, s));
    dis[s] = 0;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) {
            continue;
        }
        vis[u] = 1;
        for(int i = head[u]; i; i = nxt[i]) {
            int v = to[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                q.push(make_pair(dis[v], v));
            }
        }
    }
}

signed main() {

    n = read();
    m = read();
    s = read();

    for(int i = 1; i <= m; ++i) {
        int aa, bb, cc;
        aa = read();
        bb = read();
        cc = read();

        add_edge(aa, bb, cc);
    }

    dijsktra();

    for(int i = 1; i <= n; ++i) {
        if(dis[i] == 0x3f3f3f3f) {
            write(2147483647);
            putchar(' ');
            continue;
        }
        write(dis[i]);
        putchar(' ');
    }

    return 0;
}