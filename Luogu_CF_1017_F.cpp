#include <bits/stdc++.h>

using namespace std;
using ULL = unsigned long long;

const ULL MOD = (1ULL << 32);

ULL n, a, b, c, d;
ULL sum_ans = 0;

inline void(int p, int l, int r) {
    if(l <= r) {

    }
}

inline ULL readULL() {
    long long x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return (ULL)(x * f);
}

inline void writeULL(ULL x) {
    if ((long long)x < 0) {
        putchar('-');
        x = (ULL)(-(long long)x);
    }
    if (x > 9) writeULL(x / 10);
    putchar(char('0' + x % 10));
}

inline void writelnULL(ULL x) {
    writeULL(x);
    putchar('\n');
}

inline void init_sieve_half(ULL N, vector<ULL> &pri) {
    if (N < 2) return;
    pri.push_back(2);
    if (N < 3) return;
    size_t sz = (N + 1) / 2 + 1;
    vector<char> is_comp(sz, 0);
    ULL limit = (ULL)floor(sqrt((long double)N));
    for (ULL i = 3; i <= limit; i += 2) {
        if (!is_comp[i / 2]) {
            ULL start = i * i;
            for (ULL j = start; j <= N; j += i << 1) { // step 2*i, 保证奇数
                is_comp[j / 2] = 1;
            }
        }
    }
    for (ULL i = 3; i <= N; i += 2) {
        if (!is_comp[i / 2]) pri.push_back(i);
    }
}

inline ULL f(ULL x) {
    return ( (a * x % MOD * x % MOD * x % MOD)
           + (b * x % MOD * x % MOD)
           + (c * x % MOD)
           + d ) % MOD;
}

inline void solve(ULL N, const vector<ULL> &pri) {
    for (size_t idx = 0; idx < pri.size(); ++idx) {
        ULL p = pri[idx];
        ULL x = 0;
        for (ULL j = p; j <= N; j *= p) {
            x += N / j;
            if (j > N / p) break;
        }
        sum_ans = (sum_ans + f(p) * x % MOD) % MOD;
    }
    writelnULL(sum_ans % MOD);
}

int main() {
    n = readULL();
    a = readULL();
    b = readULL();
    c = readULL();
    d = readULL();

    vector<ULL> pri;
    pri.reserve((size_t)max<ULL>(1, min<ULL>(n, 100000)));
    init_sieve_half(n, pri);
    solve(n, pri);
    return 0;
}