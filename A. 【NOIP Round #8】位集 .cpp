#include <bits/stdc++.h>

#define N 100010
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

int n, m, q;
ll x, y, z;
ll ans, las;
int g[N];
int st[N], tp;
int a[N][25];
int siz[N];
bool mat[N][N];

int main() {
    n = read();
    m = read();
    
    for(int i = 1; i <= n; ++i) {
        static char s[N];
        scanf("%s", s + 1);
        for(int j = 1; j <= m; ++j) {
            mat[i][j] = s[j] - '0';
        }
    }
    
    q = read();
    x = read();
    y = read();
    z = read();
    
    for(int j = 1; j <= m; ++j) {
        g[j] = 1;
        st[++tp] = 1;
    }
    
    sort(st + 1, st + tp + 1);
    tp = unique(st + 1, st + tp + 1) - st - 1;
    
    for(int j = 1; j <= tp; ++j) {
        a[1][j] = st[j];
    }
    siz[1] = tp;
    
    for(int i = 2; i <= n; ++i) {
        tp = 0;
        for(int j = 1; j <= m; ++j) {
            if(mat[i][j] ^ mat[i - 1][j]) {
                g[j] = i;
            }
            st[++tp] = g[j];
        }
        
        sort(st + 1, st + tp + 1);
        tp = unique(st + 1, st + tp + 1) - st - 1;
        
        for(int j = 1; j <= tp; ++j) {
            a[i][j] = st[j];
        }
        siz[i] = tp;
    }
    
    int p = 1, q = n;
    for(int i = 1; i <= q; ++i) {
        int l = min(p, q), r = max(p, q);
        las = upper_bound(a[r] + 1, a[r] + siz[r] + 1, l) - a[r] - 1;
        p = (1ll * p * x + 1ll * las * y + z) % n + 1;
        q = (1ll * q * y + 1ll * las * z + x) % n + 1;
        ans += las;
    }
    
    writeln(ans);
    
    return 0;
}