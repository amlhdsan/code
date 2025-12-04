#include <bits/stdc++.h>

#define N 2005
#define M 305
#define inf 1e17

using namespace std;

int n, m, v, e;
int c[N][2], mp[M][M];
double k[N], dp[N][N][2], ans;

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

int main() {
    memset(mp, 63, sizeof(mp));
    
    n = read(); m = read(); v = read(); e = read();
    
    for(int i = 1; i <= n; ++i) c[i][0] = read();
    for(int i = 1; i <= n; ++i) c[i][1] = read();
    for(int i = 1; i <= n; ++i) scanf("%lf", &k[i]);
    
    for(int i = 1; i <= e; ++i) {
        int x = read(), y = read(), w = read();
        mp[x][y] = mp[y][x] = min(mp[x][y], w);
    }
    
    for(int k = 1; k <= v; ++k)
        for(int i = 1; i <= v; ++i)
            for(int j = 1; j <= v; ++j)
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
    
    for(int i = 1; i <= v; ++i) mp[i][i] = mp[i][0] = mp[0][i] = 0;
    
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= m; ++j)
            dp[i][j][0] = dp[i][j][1] = inf;
    
    dp[1][0][0] = dp[1][1][1] = 0;
    
    for(int i = 2; i <= n; ++i) {
        dp[i][0][0] = dp[i - 1][0][0] + mp[c[i - 1][0]][c[i][0]];
        for(int j = 1; j <= min(i, m); ++j) {
            int c1 = c[i - 1][0], c2 = c[i - 1][1], c3 = c[i][0], c4 = c[i][1];
            dp[i][j][0] = min(dp[i][j][0], min(dp[i - 1][j][0] + mp[c1][c3], dp[i - 1][j][1] + mp[c1][c3] * (1 - k[i - 1]) + mp[c2][c3] * k[i - 1]));
            dp[i][j][1] = min(dp[i][j][1], min(dp[i - 1][j - 1][0] + mp[c1][c3] * (1 - k[i]) + mp[c1][c4] * k[i], dp[i - 1][j - 1][1] + mp[c2][c4] * k[i] * k[i - 1] + mp[c2][c3] * k[i - 1] * (1 - k[i]) + mp[c1][c4] * (1 - k[i - 1]) * k[i] + mp[c1][c3] * (1 - k[i - 1]) * (1 - k[i])));
        }
    }
    
    ans = inf;
    for(int i = 0; i <= m; ++i) ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
    
    printf("%.2lf", ans);
    
    return 0;
}