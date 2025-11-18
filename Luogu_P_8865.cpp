#include <bits/stdc++.h>

#define N 1005
#define ll long long
#define mod 998244353

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

int T, id;
char a[N][N];
int n, m, c, f;
int r[N][N];
int d[N][N];
ll s1[N][N];
ll s2[N][N];

void dfsr(int i, int j) {
    if(a[i][j] == '1') return;
    r[i][j] = 1;
    if(j == m) return;
    dfsr(i, j + 1);
    r[i][j] = r[i][j + 1] + 1;
}

void dfsd(int i, int j) {
    if(a[i][j] == '1') return;
    d[i][j] = 1;
    if(i == n) return;
    dfsd(i + 1, j);
    d[i][j] = d[i + 1][j] + 1;
}

int main() {
    
    T = read();
    id = read();
    
    while(T--) {
        memset(r, 0, sizeof(r));
        memset(d, 0, sizeof(d));
        
        n = read();
        m = read();
        c = read();
        f = read();
        
        for(int i = 1; i <= n; ++i) {
            scanf("%s", a[i] + 1);
        }
        
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '0') {
                    if(!r[i][j]) {
                        dfsr(i, j);
                    }
                }
            }
        }
        
        for(int j = 1; j <= m; ++j) {
            for(int i = 1; i <= n; ++i) {
                if(a[i][j] == '0') {
                    if(!d[i][j]) {
                        dfsd(i, j);
                    }
                }
            }
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                s1[j][i] = (s1[j - 1][i] + (ll)(r[j][i] - 1)) % mod;
            }
        }
        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j) {
                s2[j][i] = (s2[j - 1][i] + (ll)(r[j][i] - 1) * (ll)(d[j][i] - 1)) % mod;
            }
        }
        
        ll ac = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '1') continue;
                ll c1 = r[i][j] - 1;
                int p = i + d[i][j] - 1;
                if(p <= i + 1) continue;
                ll c2 = (s1[p][j] - s1[i + 1][j] + mod) % mod;
                ac = (ac + c1 * c2 % mod) % mod;
            }
        }
        
        ll af = 0;
        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                if(a[i][j] == '1') continue;
                ll c1 = r[i][j] - 1;
                int p = i + d[i][j] - 1;
                if(p <= i + 1) continue;
                ll c2 = (s2[p][j] - s2[i + 1][j] + mod) % mod;
                af = (af + c1 * c2 % mod) % mod;
            }
        }
        
        write(ac * (ll)c);
        putchar(' ');
        writeln(af * (ll)f);
    }
    
    return 0;
}