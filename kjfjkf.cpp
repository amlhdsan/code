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
vector<int> get_primes(int x) {
    vector<int> res;
    for (int i = 2; 1LL * i * i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}

// exgcd
int exgcd(int a, int b, int &x, int &y) {
    if (!b) { x = 1, y = 0; return a; }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

signed main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        p[i] = read();
        P = lcm(P, p[i]);
    }
    int M = 2 * P;
    vector<int> primes = get_primes(M);
    int m = primes.size();
    int ans = -1;

    // 枚举所有互质划分
    for (int mask = 1; mask < (1 << m) - 1; ++mask) {
        int a = 1, b = 1;
        for (int i = 0; i < m; ++i) {
            if (mask >> i & 1) a *= primes[i];
            else b *= primes[i];
        }
        // a, b 必须互质
        if (gcd(a, b) != 1) continue;
        int x, y;
        int d = exgcd(a, b, x, y);
        // a, b 互质，d==1
        x = (x % b + b) % b; // 最小正整数解
        int t = a * x;
        if (t == 0) continue; // t>0
        if (ans == -1 || t < ans) ans = t;
    }
    writeln(ans);
    return 0;
}