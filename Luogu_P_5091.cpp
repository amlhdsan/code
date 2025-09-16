#include <iostream>
using namespace std;
typedef long long ll;

ll phi(ll n) {
    ll r = n;
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) {
            r = r / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) r = r / n * (n - 1);
    return r;
}

ll qpow(ll a, ll b, ll m) {
    ll r = 1; a %= m;
    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

ll mod(string& b, ll p) {
    bool flag = 0;
    ll r = 0;
    for (char c : b) {
        r = r * 10 + c - '0';
        if (r >= p) {
            r %= p;
            flag = 1;
        }
    }
    return flag ? r + p : r;
}

int main() {
    ll a, m;
    string b;
    cin >> a >> m >> b;
    if (m == 1) {
        cout << 0;
        return 0;
    }
    ll p = phi(m);
    ll k = mod(b, p);
    cout << qpow(a, k, m);
    return 0;
}