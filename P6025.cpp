#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;

ull pref_xor(ull x) {
    // xor of [0..x]
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
    // For k>=0, numbers i with ceil(log2(i)) == k are i in (2^{k-1}, 2^k] (with k=0 meaning i=1)
    // For such i, f(i) = i + (2^k - 1).
    // So xor over i in [lo..hi] of f(i) = xor over consecutive numbers [lo + C, hi + C].
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
    if (!(cin >> l >> r)) return 0;
    ull ans = prefix_S(r) ^ prefix_S(l - 1);
    cout << ans << '\n';
    return 0;
}