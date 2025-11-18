#include <bits/stdc++.h>

#define N 1010
#define MOD 998244353

using namespace std;

int T;
int n, m, c, f;
bool mp[N][N];
int sum = 0;
int f[N][N]; // 表示mp[i][j] 后面有多少个连续的 0

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
    m = read();
    c = read();
    f = read();
    // 从右往左扫
    for(int i = 1; i <= n; ++i) {
        for(int j = m; j >= 1; --j) {
            if()
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