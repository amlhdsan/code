#include <bits/stdc++.h>

#define int unsigned long long
#define MOD (1ULL << 32)

using namespace std;

int n, a, b, c, d;
int sum = 0;

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
    if ((long long)x < 0) {
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

inline void init_sieve(int n, vector<int> &primes) {
    vector<bool> is_comp(n + 1, false);
    if (n >= 0) is_comp[0] = true;
    if (n >= 1) is_comp[1] = true;
    for (int i = 2; i <= (int)n; ++i) {
        if (!is_comp[i]) primes.push_back(i);
        for (size_t j = 0; j < primes.size(); ++j) {
            unsigned long long prod = (unsigned long long)i * primes[j];
            if (prod > (unsigned long long)n) break;
            is_comp[(size_t)prod] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

inline int f(int x) {
    return (a * x % MOD * x % MOD * x % MOD + b * x % MOD * x % MOD + c * x % MOD + d) % MOD;
}

inline void solve(int n, int a, int b, int c, int d, const vector<int> &primes) {
    for (size_t i = 0; i < primes.size(); ++i) {
        int p = primes[i];
        unsigned long long x = 0;
        for (unsigned long long j = p; j <= (unsigned long long)n; j *= p) {
            x += n / j;
            if (j > (unsigned long long)n / p) break; // 防止溢出
        }
        sum = (sum + f(p) * x % MOD) % MOD;
    }
    writeln(sum % MOD);
}

signed main() {
    n = (int)read();
    a = (int)read();
    b = (int)read();
    c = (int)read();
    d = (int)read();

    vector<int> primes;
    primes.reserve( (size_t)max(1u, (unsigned)min((unsigned)n, 100000u)) );
    init_sieve((int)n, primes);

    solve(n, a, b, c, d, primes);

    return 0;
}