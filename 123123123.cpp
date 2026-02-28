#include <bits/stdc++.h>

#define N 505

using namespace std;

// int t = 2;
int n;
vector<int> adj[N];
int cost[N][N];
bool vis[N];
vector<int> island[N];
int islandId[N];
int islandCnt = 0;
int edgeCost = 0;

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

void dfs(int u, int id) {
    vis[u] = true;
    islandId[u] = id;
    island[id].push_back(u);
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v, id);
        }
    }
}

int main() {
    n = read();
    
    for (int i = 0; i < n; ++i) {
        int u = read(), v = read();
        adj[u].push_back(v);
        adj[v].push_back(u);
        edgeCost += cost[u][v];
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cost[i][j] = read();
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, islandCnt++);
        }
    }
    
    int ans = edgeCost * 2;
    
    for (int id = 0; id < islandCnt; ++id) {
        int minSave = INT_MAX;
        
        for (int u : island[id]) {
            for (int v : island[id]) {
                if (u != v) {
                    minSave = min(minSave, cost[u][v]);
                }
            }
        }
        
        if (minSave != INT_MAX) {
            ans -= minSave;
        }
    }
    
    if (islandCnt > 1) {
        int minBridge = INT_MAX;
        for (int id1 = 0; id1 < islandCnt; ++id1) {
            for (int id2 = id1 + 1; id2 < islandCnt; ++id2) {
                for (int u : island[id1]) {
                    for (int v : island[id2]) {
                        minBridge = min(minBridge, cost[u][v]);
                    }
                }
            }
        }
        ans += minBridge * (islandCnt - 1);
    }
    
    writeln(ans);
    
    return 0;
}