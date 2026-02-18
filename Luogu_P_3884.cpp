#include <bits/stdc++.h>

#define N 100005

using namespace std;

int n;
vector<int> e[N];
int dep[N];
int num[N];

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

inline void bfs(int s) {
    queue<int> q;
    q.push(s);
    dep[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : e[u]) {
            if (!dep[v]) {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {

    n = read();

    for(int i = 1; i < n; i++) {
        int u = read(), v = read();
        e[u].push_back(v);
        e[v].push_back(u);
    }

    // 求宽度（层数）最大的层

    bfs(1);
    for (int i = 1; i <= n; i++) {
        num[dep[i]]++;
    }
    int md = -1;
    for (int i = 1; i <= n; i++) {
        if (num[i] > num[md]) {
            md = i;
        }
    }
    writeln(num[md]);

    // 深度
    
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dep[i]);

    writeln(ans);

    // x, y;
    int x = read(), y = read();

    // dis[x, y]

    memset(dep, 0, sizeof(dep));

    bfs(x);
    writeln(dep[y]);

    return 0;
}