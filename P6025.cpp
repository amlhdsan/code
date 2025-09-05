#include <bits/stdc++.h>
using namespace std;

// 快速读入优化
inline long long read() {
    long long x = 0, f = 1;
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

// 输出优化
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

// 计算log2(n)上取整
inline int ceil_log2(long long n) {
    int l = 0, r = 63;
    while (l < r) {
        int mid = (l + r) >> 1;
        if ((1LL << mid) < n) l = mid + 1;
        else r = mid;
    }
    return l;
}

// 判断是否为2的幂
inline bool is_power_of_2(long long n) {
    return (n & (n - 1)) == 0;
}

// 递归计算f(n)
long long calc_f(long long n, long long depth) {
    if (is_power_of_2(n) || is_power_of_2(n - 1)) return 2 * n - 1;
    return calc_f(n >> 1, depth - 1) + (1LL << depth);
}

inline long long f(long long n) {
    return calc_f(n, ceil_log2(n));
}

// 计算异或前缀和
long long prefix_xor(long long n) {
    if (n == 0) return 0;
    long long ret = 0;
    map<long long, bool> vis;
    
    auto add = [&](long long x) {
        if (x <= n && !vis[x]) {
            vis[x] = true;
            ret ^= f(x);
        }
    };
    
    for (long long i = 1; i <= n; i <<= 1) {
        add(i);
        add(i + 1);
    }
    
    if ((n & 1) == 0 && !vis[n]) {
        ret ^= f(n);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long l, r;
    cin >> l >> r;
    writeln(prefix_xor(r) ^ prefix_xor(l - 1));
    
    return 0;
}