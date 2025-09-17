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

ll exphi(ll a, ll p) {
    ll r = 1, k = a;
    while (p) {
        if (p & 1) r = r * k;
        k = k * k; p >>= 1;
    }
    return r;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1; y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

inline ll ceil_div(ll a, ll b){ return a>=0 ? (a + b - 1)/b : a/b; }
inline ll floor_div(ll a, ll b){ return a>=0 ? a/b : (a - b + 1)/b; }

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
        x *= c / d; y *= c / d;
        ll tx = b / d, ty = a / d;
        ll k1 = ceil_div(1 - x, tx);
        ll k2 = floor_div(y - 1, ty);
        if (k1 > k2) {
            ll ansx = x + k1 * tx;
            ll ansy = y - k2 * ty;
            printf("%lld %lld\n", ansx, ansy);
            continue;
        }
        ll cnt = k2 - k1 + 1;
        ll cntx = 14;
        ll minx = x + k1 * tx;
        ll maxx = x + k2 * tx;
        ll miny = y - k2 * ty;
        ll maxy = y - k1 * ty;
        printf("%lld %lld %lld %lld %lld\n", cnt, minx, miny, maxx, maxy);
    }
    return 0;
}
