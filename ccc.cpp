#include <bits/stdc++.h>

#define N 100005
#define M 105

using namespace std;

int n, q;
int a[N], b[N];
int lza[N << 2], lzb[N << 2];

bitset<M> x, k;
int m;
pair<int, int> dp[M][2];
bool vis[M][2];

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

pair<int, int> dfs(int pos, int lim) {
    if(pos == -1) {
        return {0, 0};
    }
    
    if(vis[pos][lim]) {
        return dp[pos][lim];
    }
    
    if(!lim) {
        vis[pos][0] = 1;
        dp[pos][0] = {pos + 1, 0};
        return dp[pos][0];
    }
    
    pair<int, int> res = {-1, -1};
    
    int xb = x[pos];
    int kb = k[pos];
    int up = kb;
    
    for(int yb = 0; yb <= up; ++yb) {
        int nl = (yb == kb);
        
        pair<int, int> sub = dfs(pos - 1, nl);
        
        int sp = sub.first;
        int sc = sub.second;
        
        int s = xb + yb + sc;
        int cb = s & 1;
        int co = s >> 1;
        
        int tp = sp + cb;
        
        if(tp > res.first) {
            res = {tp, co};
        }
    }
    
    vis[pos][1] = 1;
    dp[pos][1] = res;
    return res;
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
            m = r - l + 1;
            
            x.reset();
            k.reset();
            
            for(int i = 0; i < m; ++i) {
                int pos = l + i;
                int bp = m - 1 - i;
                
                int ca = a[pos] ^ qry(lza, 1, 1, n, pos);
                int cb = b[pos] ^ qry(lzb, 1, 1, n, pos);
                
                if(ca) {
                    x.set(bp);
                }
                if(cb) {
                    k.set(bp);
                }
            }
            
            memset(vis, 0, sizeof(vis));
            
            pair<int, int> res = dfs(m - 1, 1);
            
            int ans = res.first + res.second;
            
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