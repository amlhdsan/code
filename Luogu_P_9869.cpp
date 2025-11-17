#include <bits/stdc++.h>

#define N 100005

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
char op[N];
int p1[N], p2[N];
int val[N];
int fa[N], neg[N];

int getf(int x) {
    if (fa[x] == x) return x;
    int p = fa[x];
    int f = getf(p);
    neg[x] ^= neg[p];
    fa[x] = f;
    return f;
}

void merge(int x, int y, int inv) {
    int fx = getf(x), fy = getf(y);
    if (fx == fy) {
        if ((neg[x] ^ neg[y]) != inv) {
            // parity contradiction inside same component -> must be Unknown
            val[fx] = 2;
        }
        return;
    }

    // need is parity between fx and fy after attaching fx -> fy
    int need = neg[x] ^ neg[y] ^ inv; // value_fx = need ? !value_fy : value_fy

    // save old values to compute merged constraint
    int vx = val[fx];
    int vy = val[fy];

    // link fx under fy
    fa[fx] = fy;
    neg[fx] = need;

    // compute new value for fy after merge
    int newv = -1;
    if (vx == 2 || vy == 2) {
        newv = 2;
    } else if (vx == -1 && vy == -1) {
        newv = -1;
    } else if (vx == -1 && vy != -1) {
        newv = vy;
    } else if (vx != -1 && vy == -1) {
        // map vx to fy according to need
        if (need == 0) newv = vx;
        else newv = (vx == 0 ? 1 : 0);
    } else {
        // both concrete (0 or 1), check consistency after mapping vx to fy
        int mapped_vx = (need == 0 ? vx : (vx == 0 ? 1 : 0));
        if (mapped_vx == vy) newv = vy;
        else newv = 2;
    }

    val[fy] = newv;
}

void solve() {
    n = read(); m = read();
    
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        neg[i] = 0;
        val[i] = -1;
    }
    
    for (int i = 1; i <= m; i++) {
        char c;
        scanf(" %c", &c);
        op[i] = c;
        if (c == 'T' || c == 'F' || c == 'U') {
            p1[i] = read();
            p2[i] = 0;
        } else {
            p1[i] = read();
            p2[i] = read();
        }
    }
    
    for (int i = m; i >= 1; i--) {
        if (op[i] == 'T') {
            int fx = getf(p1[i]);
            if (val[fx] == -1) val[fx] = neg[p1[i]] ? 1 : 0;
            else if (val[fx] != (neg[p1[i]] ? 1 : 0)) val[fx] = 2;
        } else if (op[i] == 'F') {
            int fx = getf(p1[i]);
            if (val[fx] == -1) val[fx] = neg[p1[i]] ? 0 : 1;
            else if (val[fx] != (neg[p1[i]] ? 0 : 1)) val[fx] = 2;
        } else if (op[i] == 'U') {
            int fx = getf(p1[i]);
            if (val[fx] == -1) val[fx] = 2;
        } else if (op[i] == '+') {
            merge(p1[i], p2[i], 0);
        } else {
            merge(p1[i], p2[i], 1);
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i && val[i] == 2) {
            ans++;
        }
    }
    
    writeln(ans);
}

int main() {
    int c = read(), t = read();
    while (t--) {
        solve();
    }
    return 0;
}