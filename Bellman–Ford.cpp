#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int n, m, s;

struct Edge {
    int v;
    int c;
};

vector<Edge> edges[MAXN];
int dis[MAXN];

inline int read() {
    int x = 0, f = 1;
    char ch = 0;
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void beintman_ford() {

    memset(dis, 0x3f, sizeof(dis));

    dis[s] = 0;

    bool flag;

    for(int i = 1; i <= n - 1; ++i) {
        flag = false;
        for(int u = 1; u <= n; ++u) {
            for(Edge e : edges[u]) {
                if(dis[e.v] > dis[u] + e.c) {
                    dis[e.v] = dis[u] + e.c;
                    flag = true;
                }
            }
        }
        if(!flag)
            break;
    }
}

int main() {

    n = read();
    m = read();
    s = read();
    
    for(int i = 1; i <= m; ++i) {
        int u, v, c;
        u = read();
        v = read();
        c = read();
        Edge tmp;
        tmp.c = c;
        tmp.v = v;
        edges[u].push_back(tmp);
    }

    beintman_ford();

    for(int i = 1; i <= n; ++i) {
        write((dis[i] == 0x3f3f3f3f ? 2147483647 : dis[i]));
        putchar(' ');
    }
    putchar('\n');
    return 0;
}