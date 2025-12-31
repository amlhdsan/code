#include <bits/stdc++.h>

#define N 1010

using namespace std;

int T;
int n;
int a[N];
int dp[2 * N][2 * N];

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
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    sort(a + 1, a + n + 1);

    for(int i = 1; i <= 2 * n; ++i) {
        for(int j = 1; j <= 2 * n; ++j) {
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
        }
    }
}

int main() {

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}