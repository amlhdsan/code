#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m;
// struct node {
//     int x, y;
// }a[1000010];

map<int, vector<int>> a;
set<int> nw;

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

// inline bool cmp(node x, node y) {
//     return x.x == y.x ? x.y < y.y : x.x < y.x;
// }

signed main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        int x = read();
        int y = read();
        a[x].push_back(y);
    }

    // sort(a + 1, a + 1 + m, cmp);

    nw.insert(n);

    for(auto i : a) {
        // in.clear();
        // out.clear();
        vector<int> in;
        vector<int> out;
        for(int j : i.second) {
            if(nw.count(j)) {
                out.push_back(j);
            }
            if(nw.count(j - 1) || nw.count(j + 1)) {
                in.push_back(j);
            }
        }

        for(int j : out) {
            nw.erase(j);
        }

        for(int j : in) {
            nw.insert(j);
        }
    }

    writeln(nw.size());

    return 0;
}