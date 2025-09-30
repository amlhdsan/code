// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, maxm = 2610;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, m = 2600, K, dt = 1300, t[maxn], v[maxn];
long long dp[2][maxm][maxn];

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

inline void solve() {
    n = read(), K = read();
    for(int i = 1; i <= n; i++) v[i] = read(), t[i] = read();
    memset(dp, 0x80, sizeof(dp)), dp[0][dt][0] = 0;
    int pre = 1, cur = 0;
    for(int i = 1; i <= n; i++) {
        swap(pre, cur), memset(dp[cur], 0x80, sizeof(dp[cur]));
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= K; k++) {
                dp[cur][j][k] = dp[pre][j][k];
                if(j >= t[i]) dp[cur][j][k] = max(dp[cur][j][k], dp[pre][j - t[i]][k] + v[i]);
                if(j + t[i] <= m) dp[cur][j][k] = max(dp[cur][j][k], dp[pre][j + t[i]][k] + v[i]);
                if(k && j >= 2 * t[i]) dp[cur][j][k] = max(dp[cur][j][k], dp[pre][j - 2 * t[i]][k - 1] + v[i]);
                if(k && j + 2 * t[i] <= m) dp[cur][j][k] = max(dp[cur][j][k], dp[pre][j + 2 * t[i]][k - 1] + v[i]);
            }
        }
    }
    long long ans = -inf;
    for(int i = 0; i <= K; i++) ans = max(ans, dp[cur][dt][i]);
    printf("%lld\n", ans);
}

int main() {
    freopen("enlarge.in", "r", stdin), freopen("enlarge.out", "w", stdout);
    solve();
    return 0;
}
