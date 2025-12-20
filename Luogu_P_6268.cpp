#include <bits/stdc++.h>

#define N 1005

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

int n, m;
vector<int> g[N];
int col[N];
int mat[N];
bool vis[N];

bool dfs(int u) {
    for(int v : g[u]) {
        if(vis[v]) continue;
        vis[v] = true;
        if(mat[v] == -1 || dfs(mat[v])) {
            mat[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    n = read();
    m = read();
    
    memset(col, -1, sizeof(col));
    
    for(int i = 0; i < m; ++i) {
        int u = read();
        int v = read();
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for(int i = 0; i < n; ++i) {
        if(col[i] == -1) {
            queue<int> q;
            q.push(i);
            col[i] = 0;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : g[u]) {
                    if(col[v] == -1) {
                        col[v] = col[u] ^ 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    memset(mat, -1, sizeof(mat));
    int ans = 0;
    
    for(int i = 0; i < n; ++i) {
        if(col[i] == 0) {
            memset(vis, false, sizeof(vis));
            if(dfs(i)) ans++;
        }
    }
    
    writeln(n - ans);
    
    return 0;
}