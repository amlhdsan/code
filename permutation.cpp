#include <bits/stdc++.h>

#define N 1000010
#define ll long long

using namespace std;

const int mod = 998244353;

int n, k;
ll fac[N];

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

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

ll qpow(ll a, ll b) {
    ll r = 1;
    while (b) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

ll C(int n, int m) {
    if (m > n || m < 0) return 0;
    return fac[n] * qpow(fac[m] * fac[n - m] % mod, mod - 2) % mod;
}

int main() {
    
    n = read(); k = read();
    
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    
    int m = n - k;
    ll ans = 0;
    
    for (int t = 0; t <= m; ++t) {
        ll v = C(m, t) * fac[n - 2 * t] % mod;
        if (t & 1) ans = (ans - v + mod) % mod;
        else ans = (ans + v) % mod;
    }
    
    writeln(ans);
    
    return 0;
}