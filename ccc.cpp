#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define N 100005

using namespace std;

int n, q;
int a[N], b[N];
int lza[N << 2], lzb[N << 2];

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

void pushd(int lz[], int p) {
    if(lz[p]) {
        lz[p << 1] ^= 1;
        lz[p << 1 | 1] ^= 1;
        lz[p] = 0;
    }
}

void upd(int lz[], int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr) {
        lz[p] ^= 1;
        return;
    }
    
    pushd(lz, p);
    
    int mid = (l + r) >> 1;
    if(ql <= mid) {
        upd(lz, p << 1, l, mid, ql, qr);
    }
    if(qr > mid) {
        upd(lz, p << 1 | 1, mid + 1, r, ql, qr);
    }
}

int qry(int lz[], int p, int l, int r, int x) {
    if(l == r) {
        return lz[p];
    }
    
    pushd(lz, p);
    
    int mid = (l + r) >> 1;
    if(x <= mid) {
        return qry(lz, p << 1, l, mid, x);
    } else {
        return qry(lz, p << 1 | 1, mid + 1, r, x);
    }
}

void solve() {
    n = read(), q = read();
    
    for(int i = 1; i <= n; ++i) {
        a[i] = getchar() - '0';
    }
    getchar();
    for(int i = 1; i <= n; ++i) {
        b[i] = getchar() - '0';
    }
    
    memset(lza, 0, sizeof(lza));
    memset(lzb, 0, sizeof(lzb));
    
    while(q--) {
        int op = read(), l = read(), r = read();
        
        if(op == 1) {
            upd(lza, 1, 1, n, l, r);
        }
        else if(op == 2) {
            upd(lzb, 1, 1, n, l, r);
        }
        else {
            int m = r - l + 1;
            ull x = 0, k = 0;
            
            for(int i = 0; i < m; ++i) {
                int pos = l + i;
                
                int ca = a[pos] ^ qry(lza, 1, 1, n, pos);
                int cb = b[pos] ^ qry(lzb, 1, 1, n, pos);
                
                if(ca) {
                    x |= (1ULL << (m - 1 - i));
                }
                if(cb) {
                    k |= (1ULL << (m - 1 - i));
                }
            }
            
            int ans = 0;
            for(ull y = 0; ; ++y) {
                ans = max(ans, __builtin_popcountll(x + y));
                
                if(y == k) {
                    break;
                }
            }
            
            writeln(ans);
        }
    }
}

int main() {

    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);

    int t = 1;
    
    while(t--) {
        solve();
    }
    
    return 0;
}