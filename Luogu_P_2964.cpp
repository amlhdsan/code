#include <bits/stdc++.h>

#define N 2010
// #define int long long

using namespace std;

int n;
int c[N];
int sum[N];
// int tmp = 0; // 单调不降性
int dp[N][N]; // 表示当前剩下 i -> n，现在取出 j 个的最优价值。

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

inline void print() {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            write(dp[i][j]);
    }
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        c[i] = read();
        sum[i] = sum[i - 1] + c[i];
    }

    for(int i = n; i >= 1; --i) {
        for(int j = 1; j <= n - i + 1; ++j) {
            dp[i][j] = max(max(dp[i][j], dp[i][j - 1]), sum[n] - sum[i - 1] - dp[i + j][min(j * 2, n - i - j + 1)]);
        }
    }

    print();

    writeln(max(dp[1][1], dp[1][2]));

    return 0;
}