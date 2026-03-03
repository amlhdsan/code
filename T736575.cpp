#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long ll;

// 手写 GCD 以确保兼容性
ll get_gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll g = a[0];
    for (int i = 1; i < n; ++i) g = get_gcd(g, a[i]);

    ll m = 0;
    for (int i = 1; i < n; ++i) {
        ll diff = (a[i] > a[0]) ? (a[i] - a[0]) : (a[0] - a[i]);
        m = get_gcd(m, diff);
    }

    if (m == 0) {
        cout << "infinite" << endl;
    } else {
        // 最大值 f(k) = M, 最小 k = M/g
        cout << m << " " << m / g << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}