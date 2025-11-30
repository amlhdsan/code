#include <bits/stdc++.h>

#define N 5010
#define ll long long

using namespace std;

const ll INF = 1e18;

int n, m;
ll s[N];
ll sum[N];
ll dp[N][N];

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

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int main() {
    n = read();
    m = read();
    
    for (int i = 1; i <= n; ++i) {
        s[i] = read();
    }
    
    sort(s + 1, s + n + 1);
    
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + s[i];
    }
    
    int mx = m - n;
    
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= mx; ++j) {
            dp[i][j] = INF;
        }
    }
    
    dp[0][0] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int k = i + 1; k <= n; ++k) {
            ll cost = (sum[k] - sum[i]) * (n - k);
            int w = (i == 0) ? 0 : (n - i);
            
            if (i == 0) {
                if (dp[i][0] != INF) {
                    dp[k][0] = min(dp[k][0], dp[i][0] + cost);
                }
                continue;
            }
            
            for (int j = 0; j <= mx - w; ++j) {
                if (dp[i][j] == INF) continue;
                
                for (int h = 1; ; ++h) {
                    int nw = j + h * w;
                    if (nw > mx) break;
                    dp[k][nw] = min(dp[k][nw], dp[i][j] + cost);
                }
            }
        }
    }
    
    ll ans = INF;
    
    for (int j = 0; j <= mx; ++j) {
        if (dp[n][j] == INF) continue;
        if ((mx - j) % n == 0) {
            ans = min(ans, dp[n][j]);
        }
    }
    
    writeln(ans);

    return 0;
}