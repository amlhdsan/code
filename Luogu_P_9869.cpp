#include <bits/stdc++.h>

#define N 100010

using namespace std;

int c, t, n, m;
int fa[N], siz[N], mp[N];

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

inline

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) fa[fy] = fx, siz[fx] += siz[fy];
}

bool dfs(int x, int rt, int f) {
    if(mp[x] / 2 == rt) return f ^ (mp[x] & 1);
    return dfs(mp[x] / 2, rt, f ^ (mp[x] & 1));
}

int opp(int x) {
    if(x == -1) return -2;
    if(x == -2) return -1;
    if(x == -3) return -3;
    return x ^ 1;
}

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

int main() {
    c = read(), t = read();
    while(t--) {
        int ans = 0;
        n = read(), m = read();
        for(int i = 1; i <= n; ++i) mp[i] = i * 2, fa[i] = i, siz[i] = 1;
        for(int i = 1; i <= m; ++i) {
            char opt;
            int x, y;
            scanf(" %c", &opt);
            if(opt == '+') {
                x = read(), y = read();
                mp[x] = mp[y];
            }
            else if(opt == '-') {
                x = read(), y = read();
                mp[x] = opp(mp[y]);
            }
            else if(opt == 'T') x = read(), mp[x] = -1;
            else if(opt == 'F') x = read(), mp[x] = -2;
            else x = read(), mp[x] = -3;
        }
        for(int i = 1; i <= n; ++i) if(mp[i] > 0) merge(mp[i] / 2, i);
        for(int i = 1; i <= n; ++i) if(i == find(i) && (mp[i] == -3 || (mp[i] > 0 && dfs(i, i, 0))))
            ans += siz[i];
        writeln(ans);
    }
    return 0;
}