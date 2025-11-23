#include <bits/stdc++.h>

#define ll long long
#define N 1000010

using namespace std;

int n, k;
ll a[N], b[N];
ll dp[2][N];
const ll INF = -1e18;

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

void solve() {
    n = read(), k = read();
    
    for(int i = 0; i < n; ++i) {
        a[i] = read();
    }
    for(int i = 0; i < n; ++i) {
        b[i] = read();
    }
    
    if(k == 1) {
        writeln(0);
        return;
    }
    
    for(int j = 0; j < n; ++j) {
        dp[1][j] = 0;
    }
    
    for(int i = 2; i <= k; ++i) {
        int cur = i & 1;
        int pre = (i - 1) & 1;
        
        ll maxf = INF, maxg = INF;
        
        for(int j = 0; j < n; ++j) {
            dp[cur][j] = max(b[j] + maxf, a[j] + maxg);
            maxf = max(maxf, dp[pre][j] + a[j]);
            maxg = max(maxg, dp[pre][j] + b[j]);
        }
    }
    
    ll ans = INF;
    int row = k & 1;
    
    for(int j = 0; j < n; ++j) {
        ans = max(ans, dp[row][j]);
    }
    
    writeln(ans);
}

int main() {
    int c = read(), t = read();
    
    while(t--) {
        solve();
    }
    
    return 0;
}