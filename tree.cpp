// 電影發明以後,人類的生命,比以前至少延長了三倍。
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

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

const int N = 500000 + 5;

int h[N], to[N << 1], nxt[N << 1], cnt;
int p[N], ord[N];
long long w[N], d0[N], d1[N];
bool used[N];

inline void add(int u, int v) {
    ++cnt;
    to[cnt] = v;
    nxt[cnt] = h[u];
    h[u] = cnt;
}

int main() {
    int T = read();
    while (T--) {
        int n = read();
        cnt = 0;
        for (int i = 1; i <= n; i++) h[i] = 0;

        for (int i = 1; i <= n; i++) w[i] = read();

        for (int i = 1; i < n; i++) {
            int u = read(), v = read();
            add(u, v);
            add(v, u);
        }

        int top = 0;
        p[1] = 0;
        ord[++top] = 1;

        for (int i = 1; i <= top; i++) {
            int u = ord[i];
            for (int e = h[u]; e; e = nxt[e]) {
                int v = to[e];
                if (v == p[u]) continue;
                p[v] = u;
                ord[++top] = v;
            }
        }

        for (int i = top; i; i--) {
            int u = ord[i];
            d1[u] = w[u];
            d0[u] = 0;
            for (int e = h[u]; e; e = nxt[e]) {
                int v = to[e];
                if (v == p[u]) continue;
                d1[u] += d0[v];
                d0[u] += max(d0[v], d1[v]);
            }
        }

        for (int i = 1; i <= n; i++) used[i] = false;

        static int stk[N];
        int pos = 0;
        stk[++pos] = 1;

        while (pos) {
            int u = stk[pos--];
            if (p[u] == 0) used[u] = d1[u] > d0[u];
            else {
                if (used[p[u]]) used[u] = false;
                else used[u] = d1[u] > d0[u];
            }
            for (int e = h[u]; e; e = nxt[e]) {
                int v = to[e];
                if (v == p[u]) continue;
                stk[++pos] = v;
            }
        }

        long long ans = max(d0[1], d1[1]);
        writeln(ans);

        for (int i = 1; i <= n; i++) putchar(used[i] ? '1' : '0');
        putchar('\n');
    }
    return 0;
}
