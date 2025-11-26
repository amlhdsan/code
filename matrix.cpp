#include <bits/stdc++.h>

#define int long long
#define INF 2147483648

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

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int n, m;

signed main() {
    n = read();
    m = read();

    const int N = n + 10;

    int a[N][N];
    int mi[N][N];
    int mx[N][N];
    int ok[N];
    int l[N], r[N];
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            a[i][j] = read();
        }
    }
    
    int A = 0;
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] != 0) {
                l[j] = a[i][j];
                r[j] = a[i][j];
            } else {
                l[j] = 1;
                r[j] = INF;
            }
        }
        
        for(int j = 2; j <= m; ++j) {
            l[j] = max(l[j], l[j - 1]);
        }
        for(int j = m - 1; j >= 1; --j) {
            r[j] = min(r[j], r[j + 1]);
        }
        
        int f = 1;
        for(int j = 1; j <= m; ++j) {
            if(l[j] > r[j]) {
                f = 0;
                break;
            }
        }
        
        if(f) {
            ok[i] = 1;
            A++;
            for(int j = 1; j <= m; ++j) {
                mi[i][j] = l[j];
                mx[i][j] = r[j];
            }
        }
    }
    
    int B = 0;
    for(int j = 1; j <= m; ++j) {
        int c = -1;
        int f = 1;
        
        for(int i = 1; i <= n; ++i) {
            if(a[i][j] != 0) {
                if(c == -1) {
                    c = a[i][j];
                } else if(a[i][j] != c) {
                    f = 0;
                    break;
                }
            }
        }
        
        if(!f) continue;
        
        int lo = 1, hi = INF;
        for(int i = 1; i <= n; ++i) {
            if(ok[i]) {
                lo = max(lo, mi[i][j]);
                hi = min(hi, mx[i][j]);
                if(lo > hi) break;
            }
        }
        
        if(c != -1) {
            if(lo <= c && c <= hi) B++;
        } else {
            if(lo <= hi) B++;
        }
    }
    
    write(A);
    putchar(' ');
    writeln(B);
    
    return 0;
}