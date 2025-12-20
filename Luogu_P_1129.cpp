#include <bits/stdc++.h>

#define N 210
#define PII pair<int, int>

using namespace std;

int T;
int n;
int s, t;
int m;
int a[210][210];
vector<int> e1[N];
vector<PII> e2[N];

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

inline void add_edge1(int u, int v) {
    e1[u].push_back(v);
    e1[v].push_back(u);
}

inline void solve() {
    n = read();
    m = 0;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            int tmp = read();
            if(tmp) {
                add_edge1(i, j);
                ++m;
            }
        }
    }

    s = 0;
    t = 201;


}

int main() {

    T = read();

    while(T--) {
        solve();
    }

    return 0;
}