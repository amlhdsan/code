#include<bits/stdc++.h>

#define ll long long

using namespace std;

int T;
int n;
ll a[200005], p[200005];

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

    T = read();

    while (T--) {
        n = read();
        for(int i = 1; i <= n; i++) 
            a[i] = read();
        ll ops = 0;
        ll mx = LLONG_MIN / 4;
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i >= 2) mx = max(mx, p[i - 2]);
            int s = (i % 2 == 0) ? 1 : -1;
            p[i] = p[i - 1] + s * a[i];
            if (p[i] < mx) {
                ll need = mx - p[i];
                if (i % 2 == 1) {
                    ll dec = min(need, a[i]);
                    a[i] -= dec;
                    ops += dec;
                    p[i] += dec;
                } else {
                    ll dec = min(need, a[i - 1]);
                    a[i - 1] -= dec;
                    ops += dec;
                    p[i - 1] += dec;
                    p[i] += dec;
                }
            }
        }
        writeln(ops);
    }
    return 0;
}
