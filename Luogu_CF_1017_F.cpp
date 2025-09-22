#include <bits/stdc++.h>

#define ULL unsigned long long
#define int ULL
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

inline void init(int n, vector<int> &pri) {
    vector<bool> isp(n + 1, false);
    if (n >= 0) isp[0] = true;
    if (n >= 1) isp[1] = true;
    for (int i = 2; i <= (int)n; ++i) {
        if (!isp[i]) pri.push_back(i);
        for (size_t j = 0; j < pri.size(); ++j) {
            ULL prod = (ULL)i * pri[j];
            if (prod > (ULL)n) break;
            isp[(size_t)prod] = true;
            if (i % pri[j] == 0) break;
        }
    }
}

inline int f(int x) {
    return (a * x % MOD * x % MOD * x % MOD + b * x % MOD * x % MOD + c * x % MOD + d) % MOD;
}

inline void solve(int n, int a, int b, int c, int d, const vector<int> &pri) {
    for (size_t i = 0; i < pri.size(); ++i) {
        int p = pri[i];
        ULL x = 0;
        for (ULL j = p; j <= (ULL)n; j *= p) {
            x += n / j;
            if (j > (ULL)n / p) {
                break;
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

    vector<int> pri;
    pri.reserve( (size_t)max(1u, (unsigned)min((unsigned)n, 100000u)));
    
    init((int)n, pri);

    solve(n, a, b, c, d, pri);

    return 0;
}