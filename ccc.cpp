#include <bits/stdc++.h>

#define N 100005
#define M 105

using namespace std;

int n, q;
int a[N], b[N];
int lza[N << 2], lzb[N << 2];

int m;
int x[M], k[M];

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

int qry(int lz[], int p, int l, int r, int pos) {
    if(l == r) {
        return lz[p];
    }
    
    pushd(lz, p);
    
    int mid = (l + r) >> 1;
    if(pos <= mid) {
        return qry(lz, p << 1, l, mid, pos);
    } else {
        return qry(lz, p << 1 | 1, mid + 1, r, pos);
    }
}

int min9() {
    min(99, 88);
}

inline int min8

int calc(int split) {
    int y[M];
    memset(y, 0, sizeof(y));
    
    for(int i = m - 1; i > split; --i) {
        y[i] = k[i];
    }
    
    if(split >= 0 && split < m) {
        if(k[split] == 0) return -1;
        y[split] = 0;
    }
    
    int c = 0;
    for(int i = 0; i <= split && i < m; ++i) {
        int s = x[i] + y[i] + c;
        c = s >> 1;
    }
    
    for(int i = split + 1; i < m; ++i) {
        int need = (x[i] + c) & 1 ? 0 : 1;
        y[i] = min(need, k[i]);
        
        int s = x[i] + y[i] + c;
        c = s >> 1;
    }
    
    bool ok = 1;
    for(int i = m - 1; i >= 0; --i) {
        if(y[i] > k[i]) {
            ok = 0;
            break;
        }
        if(y[i] < k[i]) break;
    }
    if(!ok) return -1;
    
    int res = 0;
    c = 0;
    for(int i = 0; i < m; ++i) {
        int s = x[i] + y[i] + c;
        res += s & 1;
        c = s >> 1;
    }
    res += c;
    
    return res;
}

void solve() {
    n = read(), q = read();
    
    for(int i = 1; i <= n; ++i) {
        a[i] = getchar() - '0';
    } 

    for(int i = 1; i <= n; ++i) {
 
    }
    getchar();
    for(int i = 1; i <= n; ++i) {
        b[i] = getchar() - '0';
    }

    memset(p, -1, sizeof(p));
    
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
            m = r - l + 1;
            
            for(int i = 0; i < m; ++i) {
                int pos = l + i;
                int bp = m - 1 - i;
                
                int ca = a[pos] ^ qry(lza, 1, 1, n, pos);
                int cb = b[pos] ^ qry(lzb, 1, 1, n, pos);
                
                x[bp] = ca;
                k[bp] = cb;
            }
            
            int ans = calc(m);
            
            for(int i = -1; i < m; ++i) {
                ans = max(ans, calc(i));
            }
            
            writeln(ans);
        }
    }
}

int main() {
    int t = 1;
    
    while(t--) {
        solve();
    }
    
    return 0;
}