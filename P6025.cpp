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

// 输出一个数并换行
inline void writeln(long long x) {
    write(x);
    putchar('\n');
}

// 计算1到n的异或和
long long prexor(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

// 计算F(n)即f(1)到f(n)的异或和
long long F(long long n) {
    if (n == 0) return 0;
    long long res = prexor(n);
    long long p = 1;
    while (p <= n) {
        long long L = p, R = min(n, 2 * p - 1);
        long long len = R - L + 1;
        if (len & 1) res ^= (2 * p - 1);
        p <<= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 读入区间边界l和r
    long long l, r;
    cin >> l >> r;
    
    // 计算f(l)到f(r)的异或和
    writeln(F(r) ^ F(l - 1));
    
    return 0;
}