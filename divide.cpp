#include <bits/stdc++.h>

#define N 100010
#define K 21

using namespace std;

int n, k;
int a[N];
int dp[N][K];

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

inline void wk(int k, int l, int r, int ql, int qr) {

}

int main() {

    // freopen("divide.in", "r", stdin);
    // freopen("divide.out", "w", stdout);

    n = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    dp[0][0] = 0;

    for(int i = 1; i <= k; ++i) {
        wk(i, 1, n, 0, n - 1);
    }

    return 0;
}