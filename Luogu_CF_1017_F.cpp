#include <bits/stdc++.h>

#define N 300000010
#define int unsigned long long
#define MOD (1 << 32)

using namespace std;

int n, a, b, c, d;
int sum = 0;
bool not_pri[N];
int pri[200010], cnt = 0;

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

inline void init() {
    for(int i = 2; i <= n; ++i) {
        if(!not_pri[i]) 
            pri[++cnt] = i;
        for(int j = 1; j <= cnt && i * pri[j] <= n; ++j) {
            not_pri[i * pri[j]] = true;
            if(i % pri[j] == 0) 
                break;
        }
    }
}

inline int f(int x) {
    return (a * x % MOD * x % MOD * x % MOD + b * x % MOD * x % MOD + c * x % MOD + d) % MOD;
}

inline void solve(int n, int a, int b, int c, int d) {
    for(int i = 1; i <= cnt; ++i) {

    }

}

int main() {

    n = read();
    a = read();
    b = read();
    c = read();
    d = read();

    init();

    solve(n, a, b, c, d);

    return 0;
}