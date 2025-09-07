// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

inline void optimizeIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

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

const int MAXN = 2000005;
int p[MAXN];
int main() {
    int n = read();
    int c = read();
    for (int i = 1; i <= n; i++) p[i] = read();
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++) p[i + n] = p[i] + c;
    long long total = 1LL * n * (n - 1) * (n - 2) / 6;
    long long bad = 0;
    int r = 2;
    for (int i = 1; i <= n; i++) {
        if (r < i + 1) r = i + 1;
        while (r < i + n && 1LL * (p[r] - p[i]) * 2 <= c) r++;
        int m = r - i - 1;
        if (m >= 2) bad += 1LL * m * (m - 1) / 2;
    }
    long long ans = total - bad;
    long long x = ans;
    if (x == 0) {
        putchar('0');
        putchar('\n');
    } else {
        if (x < 0) {
            putchar('-');
            x = -x;
        }
        char s[32];
        int idx = 0;
        while (x) {
            s[idx++] = '0' + (x % 10);
            x /= 10;
        }
        for (int i = idx - 1; i >= 0; i--) putchar(s[i]);
        putchar('\n');
    }
    return 0;
}
