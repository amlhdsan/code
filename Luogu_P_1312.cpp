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

bool check() {
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 7; ++j)
            if (g[i][j]) return false;
    return true;
}

void down() {
    for (int i = 0; i < 5; ++i) {
        int t = 0;
        for (int j = 0; j < 7; ++j) {
            if (g[i][j]) g[i][t++] = g[i][j];
        }
        while (t < 7) g[i][t++] = 0;
    }
}

bool del() {
    bool vis[N][N] = {0}, flag = 0;
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (!g[i][j]) break;
            int k = j;
            while (k < 7 && g[i][k] == g[i][j]) ++k;
            if (k - j >= 3) {
                flag = 1;
                for (int t = j; t < k; ++t) vis[i][t] = 1;
            }
            j = k - 1;
        }
    }
    
    for (int j = 0; j < 7; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (!g[i][j]) break;
            int k = i;
            while (k < 5 && g[k][j] == g[i][j]) ++k;
            if (k - i >= 3) {
                flag = 1;
                for (int t = i; t < k; ++t) vis[t][j] = 1;
            }
            i = k - 1;
        }
    }
    
    if (!flag) return false;
    
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 7; ++j)
            if (vis[i][j]) g[i][j] = 0;
    
    return true;
}

void clear() {
    while (del()) down();
}

bool dfs(int dep) {
    if (check()) return true;
    if (dep == n) return false;
    
    int tmp[N][N];
    memcpy(tmp, g, sizeof(g));
    
    for (int x = 0; x < 5; ++x) {
        for (int y = 0; y < 7; ++y) {
            if (!g[x][y]) break;
            
            for (int d = -1; d <= 1; d += 2) {
                int nx = x + d;
                if (nx < 0 || nx >= 5) continue;
                
                memcpy(g, tmp, sizeof(g));
                
                if (g[nx][y]) {
                    swap(g[x][y], g[nx][y]);
                } else {
                    g[nx][0] = g[x][y];
                    for (int k = y; k < 6; ++k) g[x][k] = g[x][k + 1];
                    g[x][6] = 0;
                }
                
                down();
                clear();
                
                if (dfs(dep + 1)) {
                    ans[dep][0] = x;
                    ans[dep][1] = y;
                    ans[dep][2] = d;
                    return true;
                }
            }
        }
    }
    
    memcpy(g, tmp, sizeof(g));
    return false;
}

int main() {
    n = read();
    
    for (int i = 0; i < 5; ++i) {
        int j = 0, x;
        while ((x = read())) g[i][j++] = x;
    }
    
    if(dfs(0)) {
        for(int i = 0; i < n; ++i) {
            write(ans[i][0]), putchar(' ');
            write(ans[i][1]), putchar(' ');
            write(ans[i][2]), putchar('\n');
        }
    } 
    else {
        write(-1), putchar('\n');
    }
    
    return 0;
}