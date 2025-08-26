// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>

#define N 200010

using namespace std;

set<int> adj[N];
int T, n;

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
    T = read();
    while (T--) {
        n = read();
        for (int i = 1; i <= n; ++i) 
            adj[i].clear();
        for (int i = 1; i <= n - 1; ++i) {
            int u, v;
            u = read();
            v = read();
            adj[u].insert(v);
            adj[v].insert(u);
        }
        if (n <= 2) {
            writeln(-1);
            continue;
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) 
        if ((int)adj[i].size() > 2) q.push(i);
        vector<array<int,3> > ops;
        while (!q.empty()) {
            int b = q.front(); q.pop();
            if ((int)adj[b].size() <= 2) continue;
            auto it = adj[b].begin();
            int a = *it; ++it;
            int c = *it;
            vector<int> tomove;
            for (int x : adj[b]) 
                if (x != a && x != c) 
                    tomove.push_back(x);
            for (int d : tomove) {
                adj[b].erase(d);
                adj[d].erase(b);
                if (!adj[c].count(d)) {
                    adj[c].insert(d);
                    adj[d].insert(c);
                }
            }
            ops.push_back({a,b,c});
            if ((int)adj[c].size() > 2) q.push(c);
            if ((int)adj[b].size() > 2) q.push(b);
        }
        if (ops.empty()) writeln(-1);
        else {
            write(ops[0][0]); putchar(' ');
            write(ops[0][1]); putchar(' ');
            writeln(ops[0][2]);
        }
    }
    return 0;
}