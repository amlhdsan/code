#include <bits/stdc++.h>

#define N 3010
#define int long long

using namespace std;

int n;
int k[N];
int dp[N];

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

int main() {
    // freopen("express.in", "r", stdin);
    // freopen("express.out", "w", stdout);

    n = read();

    for (int i = 1; i <= n; ++i) {
        k[i] = read();
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = k[1];

    int current_min_abs = intONG_MAX;

    for (int i = 2; i <= n; ++i) {
        // 更新 current_min_abs
        current_min_abs = min(current_min_abs, abs(k[i] - k[i - 1]));

        // 更新 dp[i]，从 i-1 到 i 的连续移动
        dp[i] = dp[i - 1] + abs(k[i] - k[i - 1]);

        // 更新 dp[i]，从任意 j 跳跃到 i 的最小代价
        dp[i] = min(dp[i], dp[i - 1] + current_min_abs);
    }

    // 输出结果
    int result = dp[n];
    cout << result << endl;

    return 0;
}
