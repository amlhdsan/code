#include <bits/stdc++.h>

#define ll long long

using namespace std;

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

int n;
ll a[1000010], b[1000010];
ll c[1000010], d[1000010];
ll pre[1000010], suf[1000010];
ll ans[1000010];

inline void solve() {
    n = read();
    
    for(int i = 0; i <= n + 5; ++i) {
        ans[i] = c[i] = pre[i] = suf[i] = -1e18;
    }
    
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    
    for(int i = 1; i <= n; ++i) {
        b[i] = read();
        b[i] = min(b[i], (ll)n + 1);
        c[b[i]] = max(c[b[i]], a[i]);
        d[b[i]]++;
    }
    
    pre[0] = max(pre[0], c[0]);
    for(int i = 1; i <= n + 2; ++i) {
        pre[i] = max(pre[i], max(pre[i - 1], c[i]));
    }
    
    for(int i = n + 2; i >= 0; --i) {
        suf[i] = max(suf[i], max(suf[i + 1], c[i]));
    }
    
    for(int i = 0; i <= n + 2; ++i) {
        ll num = n - d[i];
        ll mx = max((i == 0 ? -1000000000000000000LL : pre[i - 1]), suf[i + 1]) - i;
        ans[num] = max(ans[num], mx);
    }
    
    for(int i = n; i >= 1; --i) {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    
    for(int i = 1; i <= n; ++i) {
        writeln(ans[i]);
    }
}

int main() {

    int T = read();
    
    while(T--) {
        solve();
    }
    return 0;
}