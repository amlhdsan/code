#include <bits/stdc++.h>

#define N 200010

using namespace std;

int n, m;
int s = 1, t;
int kk[N];
int ind[N], outd[N];
vector<int> edges[N];
int rd[N], k = 0;

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
    edges[u].push_back(v);
}

inline void dfs(int p, int pre) {
    for(int i = kk[p]; i < edges[p].size(); i = kk[p]) {
        kk[p] = i + 1;
        dfs(edges[p][i], p);
    }
    rd[++k] = p;
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int u, v;
        u = read();
        v = read();
        add_edge(u, v);
        ++outd[u];
        ++ind[v];
    }

    int cnt = 0;

    for(int i = 1; i <= n; ++i) {
        if(outd[i] == ind[i]) {
            ++cnt;
        }
        else if(outd[i] - ind[i] == 1) {
            s = i;
        }
        else if(ind[i] - outd[i] == 1) {
            t = i;
        }
        else {
            puts("No");
            return 0;
        }
    }
    if(!(cnt == n || cnt == n - 2)) {
        puts("No");
        return 0;
    }

    for(int i = 1; i <= n; ++i) {
        sort(edges[i].begin(), edges[i].end());
    }

    dfs(s, 0);

    for(int i = k; i >= 1; --i) {
        write(rd[i]);
        putchar(' ');
    }

    return 0;
}