#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll c;
    if (!(cin >> n >> c)) return 0;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    sort(v.begin(), v.end());
    vector<ll> a(2*n);
    for (int i = 0; i < n; ++i) { a[i] = v[i]; a[i+n] = v[i] + c; }
    ll half = c / 2;
    ll total = 0;
    if (n >= 3) total = (ll)n * (n-1) * (n-2) / 6;
    ll bad = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        if (r < l) r = l;
        while (r + 1 < l + n && a[r+1] - a[l] <= half) ++r;
        ll k = r - l;
        if (k >= 2) bad += k * (k - 1) / 2;
    }
    cout << (total - bad) << "\n";
    return 0;
}