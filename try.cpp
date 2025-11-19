#include <bits/stdc++.h>

#define M 1000005
#define ll long long

using namespace std;

int n, m;
int buc[M];
ll ans;

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

inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(ll x) {
    write(x);
    putchar('\n');
}

int main() {
    n = read();
    m = read();
    
    for(int i = 1; i <= n; ++i) {
        buc[read()]++;
    }
    
    for(int i = 1; i <= m; ++i) {
        int st = (i & 1) ? 1 : 2;
        int lim = min(i - 1, m / i);
        for(int j = st; j <= lim; j += 2) {
            ans += 1ll * buc[i * j] * buc[(i - j) >> 1];
        }
    }
    
    writeln(ans);
    
    return 0;
}