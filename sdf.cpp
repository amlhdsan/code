// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
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

const int MOD = 998244353;
int t, n;
int a[205], b[205];
int dp[205][2];

int am(int x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
    return x;
}

int main() {
    t = read();
    while (t--) {
        n = read();
        for (int i = 1; i <= n; i++) a[i] = read();
        for (int i = 1; i <= n; i++) b[i] = read();
        for (int i = 0; i <= n; i++) dp[i][0] = dp[i][1] = 0;
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i][1] = 0;
            for (int prev = 0; prev <= 1; prev++) {
                for (int cur = 0; cur <= 1; cur++) {
                    int x1 = (prev == 0 ? a[i-1] : b[i-1]);
                    int y1 = (prev == 0 ? b[i-1] : a[i-1]);
                    int x2 = (cur == 0 ? a[i] : b[i]);
                    int y2 = (cur == 0 ? b[i] : a[i]);
                    if (x1 <= x2 && y1 <= y2) {
                        dp[i][cur] = am(dp[i][cur], dp[i-1][prev]);
                    }
                }
            }
        }
        int ans = am(dp[n][0], dp[n][1]);
        writeln(ans);
    }
    return 0;
}
