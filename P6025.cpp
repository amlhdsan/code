#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

ull pref_xor(ull x) {
    switch (x & 3ULL) {
        case 0: return x;
        case 1: return 1;
        case 2: return x + 1;
        default: return 0;
    }
}

ull range_xor(ull l, ull r) {
    if (l > r) return 0;
    return pref_xor(r) ^ pref_xor(l - 1);
}

ull prefix_S(ull N) {
    if (N == 0) return 0;
    ull res = 0;
    for (int k = 0; k <= 60; ++k) {
        ull p = 1ULL << k; // 2^k
        ull lo = (k == 0) ? 1 : ((1ULL << (k - 1)) + 1ULL);
        ull hi = min<ull>(N, p);
        if (lo > hi) continue;
        ull C = p - 1ULL;
        ull a = lo + C;
        ull b = hi + C;
        res ^= range_xor(a, b);
        if (p > N) break;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long l, r;
    cin >> l >> r;
    ull ans = prefix_S(r) ^ prefix_S(l - 1);
    cout << ans << '\n';
    return 0;
}