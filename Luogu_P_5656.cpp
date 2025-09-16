#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int T = read();
    while (T--) {
        ll a = read(), b = read(), c = read();
        ll x, y;
        ll d = exgcd(a, b, x, y);
        if (c % d) {
            puts("-1");
            continue;
        }
        x *= c / d, y *= c / d;
        ll tx = b / d, ty = a / d;
        ll k1 = ceil((-x * 1.0) / tx);
        ll k2 = floor((y * 1.0) / ty);
        if (k1 > k2) {
            ll k = ceil(-x * 1.0 / tx);
            ll ansx = x + k * tx;
            k = ceil(-y * 1.0 / ty);
            ll ansy = y + k * ty;
            printf("%lld %lld\n", ansx, ansy);
            continue;
        }
        ll cnt = k2 - k1 + 1;
        ll minx = x + k1 * tx;
        ll miny = y - k1 * ty;
        ll maxx = x + k2 * tx;
        ll maxy = y - k2 * ty;
        printf("%lld %lld %lld %lld %lld\n", cnt, minx, miny, maxx, maxy);
    }
    return 0;
}