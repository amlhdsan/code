#include <bits/stdc++.h>

#define N 10010
#define ll long long

using namespace std;

const int P = 998244353;

int n, s;
int a[N], c[N];
int b[N], h;
int fac[N], ifac[N], pw2[N];

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

inline void add(int &x, int y) {
    x = (x + y) % P;
}

ll qpow(ll a, ll b) {
    if (!b) return 1;
    return ((b & 1) ? a : 1ll) * qpow(a * a % P, b >> 1) % P;
}

void init() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
    ifac[N - 1] = qpow(fac[N - 1], P - 2);
    for (int i = N - 2; i >= 1; --i) {
        ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
    }
    pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
        pw2[i] = pw2[i - 1] * 2 % P;
    }
}

ll C(ll a, ll b) {
    if (a < b || a < 0 || b < 0) return 0;
    return 1ll * fac[a] * ifac[b] % P * ifac[a - b] % P;
}

void solve() {
    n = read();
    s = read();
    h = 0;
    
    for (int i = 0; i <= n + 1; ++i) {
        a[i] = b[i] = 0;
    }
    
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        b[++h] = a[i];
    }
    
    sort(b + 1, b + n + 1);
    h = unique(b + 1, b + h + 1) - b - 1;
    
    for (int i = 1; i <= h; ++i) {
        c[i] = 0;
    }
    
    sort(a + 1, a + n + 1);
    int ans = 0;
    
    for (int i = 1; i <= n; ++i) {
        int stl = 0, stk = 0;
        
        for (int j = 0; j <= n; ++j) {
            if (a[i] > a[j] * 2) {
                int vk = a[i] - a[j];
                int l = 0, m = 0, r = 0, tl = 0;
                
                while (stl <= n && a[n - stl] >= vk) stl++;
                while (stk <= n && a[n - stk] * 2 > a[i]) stk++;
                
                l = n - i;
                r = max(0, j - 1);
                tl = stl - l - 1;
                m = stk - stl;
                
                int tex = s - l - 1, ex = 0;
                if (tex >= 0) {
                    add(ans, -1ll * C(l + tl, tex) * C(m, s - l - tex - 1) % P * pw2[r] % P);
                }
                int res = 0;
                res = C(l + tl + m, s - l - 1) * pw2[r] % P;
                add(ans, res);
            }
        }
    }
    
    ans = ((pw2[n] - ans) % P + P) % P;
    writeln(ans);
}

int main() {
    init();
    
    int c = read(), t = read();
    while (t--) {
        solve();
    }
    
    return 0;
}