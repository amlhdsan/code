#include <bits/stdc++.h>

#define N 10

using namespace std;

int n, g[N][N];
int ans[N][3];

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

void upd() {
    for (int i = 0; i < 5; ++i) {
        int t = 0;
        for (int j = 0; j < 7; ++j) {
            if (g[i][j]) {
                if (j != t) {
                    g[i][t] = g[i][j];
                    g[i][j] = 0;
                }
                t++;
            }
        }
    }
}

bool del() {
    bool vis[N][N] = {0}, flag = 0;
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (g[i][j] && g[i][j] == g[i][j + 1] && g[i][j] == g[i][j + 2]) {
                vis[i][j] = vis[i][j + 1] = vis[i][j + 2] = 1;
                flag = 1;
            }
        }
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (g[i][j] && g[i][j] == g[i + 1][j] && g[i][j] == g[i + 2][j]) {
                vis[i][j] = vis[i + 1][j] = vis[i + 2][j] = 1;
                flag = 1;
            }
        }
    }
    
    if (!flag) return 0;
    
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 7; ++j)
            if (vis[i][j]) g[i][j] = 0;
    
    return 1;
}

void proc() {
    upd();
    while (del()) upd();
}

bool check() {
    for (int i = 0; i < 5; ++i)
        if (g[i][0]) return 0;
    return 1;
}

bool chk() {
    int cnt[11] = {0};
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 7; ++j)
            if (g[i][j]) cnt[g[i][j]]++;
    
    for (int i = 1; i <= 10; ++i)
        if (cnt[i] > 0 && cnt[i] < 3) return 0;
    return 1;
}

void dfs(int dep) {
    if (check()) {
        if (dep == n) {
            for (int i = 0; i < n; ++i) {
                write(ans[i][0]), putchar(' ');
                write(ans[i][1]), putchar(' ');
                write(ans[i][2]), putchar('\n');
            }
            exit(0);
        }
        return;
    }
    
    if (dep == n) return;
    if (!chk()) return;
    
    int tmp[N][N];
    memcpy(tmp, g, sizeof(g));
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!g[i][j]) continue;
            
            if (i < 4) {
                swap(g[i][j], g[i + 1][j]);
                ans[dep][0] = i;
                ans[dep][1] = j;
                ans[dep][2] = 1;
                proc();
                dfs(dep + 1);
                memcpy(g, tmp, sizeof(g));
            }
            
            if (i > 0 && !g[i - 1][j]) {
                swap(g[i][j], g[i - 1][j]);
                ans[dep][0] = i;
                ans[dep][1] = j;
                ans[dep][2] = -1;
                proc();
                dfs(dep + 1);
                memcpy(g, tmp, sizeof(g));
            }
        }
    }
}

int main() {
    n = read();
    
    for (int i = 0; i < 5; ++i) {
        int j = 0, x;
        while ((x = read())) g[i][j++] = x;
    }
    
    dfs(0);
    
    write(-1), putchar('\n');
    
    return 0;
}