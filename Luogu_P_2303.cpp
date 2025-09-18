// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

inline unsigned long long read() {
    unsigned long long x = 0, f = 1;
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

inline void write(unsigned long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(unsigned long long x) {
    write(x);
    putchar('\n');
}

unsigned long long phi(unsigned long long x) {
    unsigned long long res = x;
    for (unsigned long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    markdown();
    if (x > 1) res = res / x * (x - 1);
    return res;
}

int main() {
    unsigned long long n = read();
    unsigned long long ans = 0;
    for (unsigned long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans += i * phi(n / i);
            if (i * i != n) ans += (n / i) * phi(i);
        }
    }
    writeln(ans);
    return 0;
}
