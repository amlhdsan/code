#include <bits/stdc++.h>

#define N 100010
#define int long long

using namespace std;

int n;
int p[N];
int P = 1;

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

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

// 分解质因数
vector<pair<int, int>> factorize(int x) {
    vector<pair<int, int>> res;
    for (int i = 2; 1LL * i * i <= x; ++i) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0) x /= i, ++cnt;
            res.push_back({i, cnt});
        }
    }
    if (x > 1) res.push_back({x, 1});
    return res;
}

int exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1, y = 0; return a; }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

bool merge(int a1, int m1, int a2, int m2, int &a, int &m) {
    int x, y;
    int d = exgcd(m1, m2, x, y);
    if ((a2 - a1) % d) return false;
    int mod = m1 / d * m2;
    x = ((a2 - a1) / d * x % (m2 / d) + (m2 / d)) % (m2 / d);
    a = (x * m1 + a1) % mod;
    if (a < 0) a += mod;
    m = mod;
    return true;
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        p[i] = read();
        P = lcm(P, p[i]);
    }

    vector<pair<int, int>> pf = factorize(P);
    int m = pf.size();
    vector<int> primes;
    for (auto &pr : pf) primes.push_back(pr.first);

    int ans = -1;
    for (int mask = 0; mask < (1 << m); ++mask) {
        int a = 0, mod = 1;
        bool ok = true;
        for (int i = 0; i < m; ++i) {
            int rem = (mask >> i & 1) ? (primes[i] - 1) : 0; // x ≡ 0 或 x ≡ -1
            int na, nmod;
            if (!merge(a, mod, rem, primes[i], na, nmod)) {
                ok = false;
                break;
            }
            a = na;
            mod = nmod;
        }
        if (!ok) continue;
        if (a == 0) a += mod; // x > 0
        if (ans == -1 || a < ans) ans = a;
    }
    writeln(ans);

    return 0;
}