#include <bits/stdc++.h>
using namespace std;

#define N 100010

bool pri[N];

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

inline void init(int x) {
    memset(pri, true, sizeof(pri));
    pri[0] = pri[1] = false;
    for (int i = 2; i * i <= x; i++) {
        if (pri[i]) {
            for (int j = i * i; j <= x; j += i) {
                pri[j] = false;
            }
        }
    }
    return;
}

inline int phi(int x) {
    if (x == 1) return 1;
    int t = x;
    int res = x;
    for (int i = 2; i * i <= t; ++i) {
        if (pri[i] && t % i == 0) {
            while (t % i == 0) t /= i;
            res = res / i * (i - 1);
        }
    }
    if (t > 1) res = res / t * (t - 1);
    return res;
}

inline void solve(int x) {
    int ans = 0;
    for(int i = 1; i <= x; ++i) {
        ans += (((int)(x / i)) ^ 2) * phi(i);
    }
    writeln(ans);
    return;   
}

int main() {

    int n = read();

    init(n);

    solve(n);

    return 0;
}