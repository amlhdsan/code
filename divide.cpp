#include <bits/stdc++.h>

#define N 100010
#define K 21

using namespace std;

int n, k;
int a[N];
int dp[N][K];

int ql = 1, qr = 0;
int t = 0;
int cnt[N];

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

inline int cal(int l, int r) {
    while(ql > l) t += cnt[a[--ql]]++;
    while(qr < r) t += cnt[a[++qr]]++;
    while(ql < l) t -= --cnt[a[ql++]];
    while(qr > r) t -= --cnt[a[qr--]];
    return t;
}

inline void wk(int k, int l, int r, int dl, int dr) {
    if(l > r) return;
    int mid = (l + r) >> 1;
    int pos = 0; // 默认不分割
    for(int i = dl; i <= min(mid - 1, dr); ++i) {
        int cst = cal(i + 1, mid);
        if(dp[mid][k] > dp[i][k - 1] + cst) {
            dp[mid][k] = dp[i][k - 1] + cst;
            pos = i;
        }
    }
    wk(k, l, mid - 1, dl, pos);
    wk(k, mid + 1, r, pos, dr);
}

int main() {

    // freopen("divide.in", "r", stdin);
    // freopen("divide.out", "w", stdout);

    n = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    memset(dp, 0x3f, sizeof(dp));

    dp[0][0] = 0;

    for(int i = 1; i <= k; ++i) {
        wk(i, 1, n, 0, n - 1);
    }

    writeln(dp[n][k]);

    return 0;
}