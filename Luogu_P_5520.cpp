#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll ans = 1, type, n, m, p;

inline ll read() {
    ll x = 0, f = 1;
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
    type = read();
    n = read();
    m = read();
    p = read();
    
    for(int i = n - m + 1; i >= n - 2 * m + 2; --i) {
        ans = (ans * i) % p;
    }
    
    writeln(ans);
    
    return 0;
}