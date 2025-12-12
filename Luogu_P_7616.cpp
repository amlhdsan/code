#include <bits/stdc++.h>

#define N 1005
#define ll long long
#define MOD 1000000000

using namespace std; 

ll n, m, a[N], b[N], ans = 1, g;
bool flag = false;

ll gcd(ll x, ll y) {
    return y ? gcd(y, x % y) : x;
}

inline ll read() {
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

int main() {
    n = read();
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    m = read();
    for(int i = 1; i <= m; ++i) {
        b[i] = read();
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            g = gcd(a[i], b[j]);
            if(ans * g >= MOD) {
                flag = true;
                ans = (ans * g) % MOD;
            }
            else {
                ans *= g;
            }
            a[i] /= g;
            b[j] /= g;
        }
    }
    if(flag) {
        printf("%09lld", ans);
    }
    else {
        write(ans);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = )
    }
    return 0;
}