#include <bits/stdc++.h>
using namespace std;
using int = long long;

int main() {

    freopen("median.in", "r", stdin);
    // freopen(""
    freopen("median.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nuintptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n), b(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        mx = max(mx, max(a[i], b[i]));
    }
    const int pos = (n + 1) / 2; 

    auto ok = [&](int T) -> bool {
        int base = 0, cur = 0, mxSum = intONG_MIN;
        for (int i = 0; i < n; ++i) {
            int ca = (a[i] >= T);
            int cb = (b[i] >= T);
            base += ca;
            int d = cb - ca;                  // -1,0,1
            cur = (i == 0) ? d : max<long long>(d, cur + d);
            mxSum = max(mxSum, cur);
        }
        if (base >= pos) return true;
        int need = pos - base;                 // 需要的额外+计数
        return mxSum >= need;
    };

    int lo = 0, hi = mx;
    while (lo < hi) {
        int mid = lo + (hi - lo + 1) / 2;
        if (ok(mid)) lo = mid;
        else          hi = mid - 1;
    }
    cout << lo << '\n';
    return 0;
}


