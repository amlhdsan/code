// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
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

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

const int N = 200005;
int n, t;
int head[N], ver[N << 1], nxt[N << 1], tot;
int dist[N], p[N], on_diameter[N];

void add(int u, int v) {
    ver[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void dfs(int u, int fa) {
    p[u] = fa;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = ver[i];
        if (v != fa) {
            dist[v] = dist[u] + 1;
            dfs(v, u);
        }
    }
}

int main() {
    t = read();
    while (t--) {
        n = read();
        tot = 0;
        for (int i = 1; i <= n; i++) head[i] = 0, on_diameter[i] = 0;

        for (int i = 1; i < n; i++) {
            int u = read(), v = read();
            add(u, v), add(v, u);
        }

        dist[1] = 0;
        dfs(1, 0);
        int x = 1;
        for (int i = 1; i <= n; i++) if (dist[i] > dist[x]) x = i;

        dist[x] = 0;
        dfs(x, 0);
        int y = 1;
        for (int i = 1; i <= n; i++) if (dist[i] > dist[y]) y = i;

        if (dist[y] == n - 1) {
            writeln(-1);
        } else {
            int now = y;
            while (now) {
                on_diameter[now] = 1;
                now = p[now];
            }
            int a = -1, b = -1, c = -1;
            for (int u = 1; u <= n; u++) {
                for (int i = head[u]; i; i = nxt[i]) {
                    int v = ver[i];
                    if (on_diameter[u] && !on_diameter[v]) {
                        a = p[u], b = u, c = v;
                        break;
                    }
                }
                if (a != -1) break;
            }
            write(a), putchar(' '), write(b), putchar(' '), writeln(c);
        }
    }
    return 0;
}
