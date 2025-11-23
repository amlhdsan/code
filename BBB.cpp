#include <bits/stdc++.h>

#define ll long long
#define N 100005
#define MOD 998244353

using namespace std;

int n;
vector<int> adj[N], ch[N];
int tin[N], tout[N], flat[N];
int timer;

struct BIT {
    int t[N], n;
    
    void init(int sz) {
        n = sz;
        memset(t, 0, sizeof(t));
    }
    
    void add(int x, int v) {
        for(++x; x <= n; x += x & -x) {
            t[x] += v;
        }
    }
    
    int qry(int x) {
        int s = 0;
        for(++x; x > 0; x -= x & -x) {
            s += t[x];
        }
        return s;
    }
    
    int qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
} bit;

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

ll qpow(ll a, ll b) {
    ll res = 1;
    a %= MOD;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int u, int p) {
    tin[u] = timer++;
    flat[tin[u]] = u;
    
    for(int v : adj[u]) {
        if(v != p) {
            ch[u].push_back(v);
            dfs(v, u);
        }
    }
    tout[u] = timer;
}

struct Qry {
    int id, val;
};

vector<Qry> qs[N], qe[N];
ll ans[N];

void solve() {
    n = read();
    
    for(int i = 0; i < n; ++i) {
        adj[i].clear();
        ch[i].clear();
        qs[i].clear();
        qe[i].clear();
    }
    timer = 0;
    
    for(int i = 0; i < n - 1; ++i) {
        int u = read(), v = read();
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(0, -1);
    
    int qid = 0;
    
    for(int u = 0; u < n; ++u) {
        sort(ch[u].begin(), ch[u].end());
        
        for(int c : ch[u]) {
            int l = tin[c];
            int r = tout[c] - 1;
            
            qs[l].push_back({qid, c});
            qe[r].push_back({qid, c});
            ans[qid] = 0;
            qid++;
        }
    }
    
    bit.init(n);
    ll tot = 0;
    
    for(int i = 0; i < n; ++i) {
        int v = flat[i];
        
        for(auto q : qs[i]) {
            int cnt = bit.qry(q.val + 1, n - 1);
            ans[q.id] -= cnt;
        }
        
        bit.add(v, 1);
        
        for(auto q : qe[i]) {
            int cnt = bit.qry(q.val + 1, n - 1);
            ans[q.id] += cnt;
        }
    }
    
    for(int i = 0; i < qid; ++i) {
        tot += ans[i];
    }
    
    writeln(qpow(2, tot));
}

int main() {

    freopen("dfs.in", "r", stdin);
    freopen("dfs.out", "w", stdout);

    int c = read(), t = read();
    
    while(t--) {
        solve();
    }
    
    return 0;
}