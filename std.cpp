// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
int n;
long long t;
int a[N];
long long dp[N];
int q[N];

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

bool ok(int w) {
    if (w >= n) return true;
    int head = 0, tail = -1;
    dp[0] = 0;
    q[++tail] = 0;
    for (int j = 1; j <= n; j++) {
        while (head <= tail && q[head] < j - (w + 1)) head++;
        long long best = (head <= tail ? dp[q[head]] : (long long)1e18);
        dp[j] = a[j] + best;
        while (head <= tail && dp[q[tail]] >= dp[j]) tail--;
        q[++tail] = j;
    }
    long long ans = (long long)1e18;
    int L = max(1, n - w);
    for (int i = L; i <= n; i++) if (dp[i] < ans) ans = dp[i];
    return ans <= t;
}

int main() {
    n = read();
    t = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int l = 0, r = n, ans = n;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (ok(m)) {
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    writeln(ans);
    return 0;
}
