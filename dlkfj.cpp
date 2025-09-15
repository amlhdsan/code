// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

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

inline void write(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

const int N = 200005;
int a[N], f[N], pre[N];

int main() {
    int T = read();
    while (T--) {
        int n = read(), y = read();
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            f[a[i]]++;
            if (a[i] > mx) mx = a[i];
        }
        pre[0] = 0;
        for (int i = 1; i <= mx; i++) pre[i] = pre[i-1] + f[i];
        long long ans = LLONG_MIN;
        for (int x = 2; x <= mx + 1; x++) {
            int mk = (mx + x - 1) / x;
            long long sum = 0, ov = 0;
            for (int k = 1; k <= mk; k++) {
                int l = (k - 1) * x + 1;
                int r = min(mx, k * x);
                if (l > mx) break;
                int cnt = pre[r] - pre[l-1];
                sum += 1LL * k * cnt;
                if (k <= mx) ov += min(f[k], cnt);
            }
            long long pr = n - ov;
            long long inc = sum - 1LL * y * pr;
            if (inc > ans) ans = inc;
        }
        writeln(ans);
        for (int i = 1; i <= mx; i++) f[i] = 0;
    }
    return 0;
}
