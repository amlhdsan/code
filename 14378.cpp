#include <bits/stdc++.h>

#define N 500005
#define ll long long
#define inf 1e18

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

inline int lg(int x) {
    int res = 0;
    while ((1 << (res + 1)) <= x) ++res;
    return res;
}

int n, k, q;
ll a[N], g[N], val[N];
ll mn[N], mx[N], mn2[N], mx2[N];
ll fmn[N][20], fmx[N][20];
ll fmn2[N][20], fmx2[N][20];

struct node {
    int cnt;
    ll v;
} b[N];

inline bool cmp(node x, node y) {
    return x.v < y.v;
}

inline ll qmx(int l, int r) {
    int s = lg(r - l + 1);
    return max(fmx[l][s], fmx[r - (1 << s) + 1][s]);
}

inline ll qmn(int l, int r) {
    int s = lg(r - l + 1);
    return min(fmn[l][s], fmn[r - (1 << s) + 1][s]);
}

inline ll qmx2(int l, int r) {
    int s = lg(r - l + 1);
    return max(fmx2[l][s], fmx2[r - (1 << s) + 1][s]);
}

inline ll qmn2(int l, int r) {
    int s = lg(r - l + 1);
    return min(fmn2[l][s], fmn2[r - (1 << s) + 1][s]);
}

int main() {
    n = read(); k = read(); q = read();
    
    for (int i = 1; i <= n; ++i) a[i] = read(), g[i] = a[i];
    for (int i = 1; i <= k; ++i) b[i].cnt = read();
    for (int i = 1; i <= k; ++i) b[i].v = read();
    
    sort(b + 1, b + k + 1, cmp);
    
    int tot = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= b[i].cnt; ++j) {
            val[++tot] = b[i].v;
        }
    }
    
    sort(g + 1, g + n + 1);
    
    for (int i = 0; i <= n + 2; ++i) {
        mn[i] = mn2[i] = inf;
        mx[i] = mx2[i] = -inf;
    }
    
    for (int i = 1; i <= n; ++i) {
        mn[i] = min(mn[i - 1], g[i] + val[n - i + 1]);
        mx[i] = max(mx[i - 1], g[i] + val[n - i + 1]);
    }
    
    for (int i = n; i >= 1; --i) {
        mn2[i] = min(mn2[i + 1], g[i] + val[n - i + 1]);
        mx2[i] = max(mx2[i + 1], g[i] + val[n - i + 1]);
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i < n) {
            fmx[i][0] = fmn[i][0] = g[i] + val[n - i];
        } else {
            fmx[i][0] = -inf;
            fmn[i][0] = inf;
        }
    }
    
    for (int j = 1; j <= 19; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            fmx[i][j] = max(fmx[i][j - 1], fmx[i + (1 << (j - 1))][j - 1]);
            fmn[i][j] = min(fmn[i][j - 1], fmn[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        if (i >= 2) {
            fmx2[i][0] = fmn2[i][0] = g[i] + val[n - i + 2];
        } else {
            fmx2[i][0] = -inf;
            fmn2[i][0] = inf;
        }
    }
    
    for (int j = 1; j <= 19; ++j) {
        for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
            fmx2[i][j] = max(fmx2[i][j - 1], fmx2[i + (1 << (j - 1))][j - 1]);
            fmn2[i][j] = min(fmn2[i][j - 1], fmn2[i + (1 << (j - 1))][j - 1]);
        }
    }
    
    while (q--) {
        int i = read();
        ll v = read();
        
        if (a[i] == v) {
            writeln(mx[n] - mn[n]);
            continue;
        }
        
        ll MN = inf, MX = -inf;
        
        if (a[i] > v) {
            int x = upper_bound(g + 1, g + n + 1, v) - g - 1;
            MN = min(MN, mn[x]);
            MX = max(MX, mx[x]);
            MN = min(MN, v + val[n - x]);
            MX = max(MX, v + val[n - x]);
            
            x = lower_bound(g + 1, g + n + 1, a[i]) - g + 1;
            if (x <= n) {
                MN = min(MN, mn2[x]);
                MX = max(MX, mx2[x]);
            }
            
            int l = upper_bound(g + 1, g + n + 1, v) - g;
            int r = lower_bound(g + 1, g + n + 1, a[i]) - g - 1;
            if (l <= r) {
                MX = max(MX, qmx(l, r));
                MN = min(MN, qmn(l, r));
            }
            
            writeln(MX - MN);
        } else {
            int x = upper_bound(g + 1, g + n + 1, a[i]) - g - 2;
            if (x > 0) {
                MN = min(MN, mn[x]);
                MX = max(MX, mx[x]);
            }
            
            x = lower_bound(g + 1, g + n + 1, v) - g;
            MN = min(MN, mn2[x]);
            MX = max(MX, mx2[x]);
            
            x = lower_bound(g + 1, g + n + 1, v) - g - 1;
            MN = min(MN, v + val[n - x + 1]);
            MX = max(MX, v + val[n - x + 1]);
            
            int l = upper_bound(g + 1, g + n + 1, a[i]) - g;
            int r = lower_bound(g + 1, g + n + 1, v) - g - 1;
            if (l <= r) {
                MX = max(MX, qmx2(l, r));
                MN = min(MN, qmn2(l, r));
            }
            
            writeln(MX - MN);
        }
    }
    
    return 0;
}