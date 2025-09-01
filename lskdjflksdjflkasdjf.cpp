// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <iostream>
using namespace std;
using int = long long;

const int MAXN = 4000010;

int n, m, p;
int fac[MAXN], ifac[MAXN];

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

int qpow(int a, int b) {
    int r = 1;
    a %= p;
    while (b) {
        if (b & 1) r = r * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return r;
}

int inv(int x) {
    return qpow(x, p - 2);
}

void init(int mx) {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= mx; i++) fac[i] = fac[i - 1] * i % p;
    ifac[mx] = inv(fac[mx]);
    for (int i = mx - 1; i >= 1; i--) ifac[i] = ifac[i + 1] * (i + 1) % p;
}

int C(int a, int b) {
    if (b < 0 || b > a) return 0;
    return fac[a] * ifac[b] % p * ifac[a - b] % p;
}

void solve() {
    n = read(), m = read();
    if (n == 0) {
        writeln(0);
        return;
    }
    int mx = n * m + 2 * n;
    if(mx >= MAXN) return;
    int cnt = 0;
    for (int i = 0; i <= 2 * n; i++) {
        int t1 = C(2 * n, i);
        int t2 = C(n * m - i * (m + 1) + 2 * n - 1, 2 * n - 1);
        int cur = t1 * t2 % p;
        if (i & 1) cnt = (cnt - cur + p) % p;
        else cnt = (cnt + cur) % p;
    }
    int tot = qpow(m + 1, 2 * n);
    int num = (tot - cnt + p) % p;
    int den = 2 * tot % p;
    int ans = num * inv(den) % p;
    writeln(ans);
}

int main() {

    // freopen("pr.in", "r", stdin);
    // freopen("pr.out", "w", stdout);

    p = read();

    init(4000000);

    int t = read();
    while(t--) {
        solve();
    }
    return 0;
}
