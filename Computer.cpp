#include <bits/stdc++.h>

#define int long long
#define N 5010

using namespace std;

int n, m;
int dp[N][N]; // dp[i][j] 表示当前考虑前 i 台电脑，其中手动打开了 j 台。

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

inline int qpow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        b >>= 1;
    }
    return res;
}

signed main() {

    // freopen("Computer.in", "r", stdin);
    // freopen("Computer.out", "w", stdout);

    n = read();
    m = read();

    dp[1][1] = 1;

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= i; ++j) {
            dp[i][j] = (2 * dp[i - 1][j] + dp[i - 2][j - 1]) * j % m;
        }
    }

    int res = 0;

    for(int i = 1; i <= n; ++i) {
        res = (res + dp[n][i]) % m;
    }

    writeln(res);

    return 0;
}