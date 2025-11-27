// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int n;
int a[MAXN], b[MAXN];
long long d[MAXN];
int idx[MAXN];
int s[MAXN];

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

int main() {
    n = read();
    int m = 2 * n;
    for (int i = 1; i <= m; ++i) a[i] = read();
    for (int i = 1; i <= m; ++i) b[i] = read();
    for (int i = 1; i <= m; ++i) {
        d[i] = (long long)a[i] - (long long)b[i];
        idx[i] = i;
        s[i] = 1;
    }
    sort(idx + 1, idx + 1 + m, [&](int x, int y){ return d[x] < d[y]; });
    long long ans = 0;
    for (int i = 1; i <= m; ++i) ans += b[i];
    for (int k = 1; k <= n; ++k) {
        int i = idx[k];
        s[i] = 0;
        ans += d[i];
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= m; ++i) {
        if (i > 1) putchar(' ');
        write(s[i]);
    }
    putchar('\n');
    return 0;
}
