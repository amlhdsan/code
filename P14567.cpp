#include <bits/stdc++.h>

#define N 1000010
#define ll long long

using namespace std;

int n;
ll c[N], v[N], f[N];
ll cnt0[N], cnt[N];
ll sum, ans;
int vis[N];

inline ll read() {
    ll x = 0, f = 1;
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
    n = read();
    
    for(int i = 1; i <= n; ++i) {
        c[i] = read();
        cnt0[c[i]]++;
    }
    
    for(int i = 1; i <= n; ++i) {
        v[i] = read();
    }
    
    for(int i = 1; i <= n; ++i) {
        f[i] = read();
        ans += v[i] * c[i];
    }
    
    for(int i = 1; i <= n; ++i) {
        if(vis[c[i]]) continue;
        vis[c[i]] = 1;
        
        for(int j = 1; j <= n; ++j) {
            cnt[j] = 0;
        }
        
        sum = 0;
        cnt[c[i]]++;
        int flag = n - 1;
        if(cnt[c[i]] == cnt0[c[i]]) flag++;
        sum += v[i] * f[1];
        
        for(int j = i + 1; j <= n && flag != n; ++j) {
            if(!cnt[c[j]]) flag--;
            cnt[c[j]]++;
            if(cnt[c[j]] == cnt0[c[j]]) flag++;
            sum += v[j] * f[j - i + 1];
        }
        
        if(flag == n) ans = min(ans, sum);
    }
    
    writeln(ans);
    
    return 0;
}