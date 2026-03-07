// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

inline void build() {
    
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

const int N = 35;
const int M = 1005;

int m;
int a[N];
ll dp[M];

void solve() {
    m = read();
    int mx = 0;
    for (int i = 0; i < m; i++) {
        a[i] = read();
        if (a[i] > mx) mx = a[i];
    }
    for (int i = 0; i <= mx; i++) dp[i] = 0;
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = mx; j >= a[i]; j--) {
            dp[j] += dp[j - a[i]];
        }
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += dp[a[i]] - 1;
    }
    writeln(ans);
}

int main() {
    int t = read();
    while (t--) solve();
    return 0;
}