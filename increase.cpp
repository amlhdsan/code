#include <bits/stdc++.h>

#define N 2000010

using namespace std;

int ans[N];
int n, m;
bool tag[N];

struct edges{
    int u, v;
    int c;
}a[N];

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

inline bool cmp(edges a, edges b) {
    return a.c < b.c;
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= m; ++i) {
        a[i].u = read();
        a[i].v = read();
        a[i].c = read();
    }

    sort(a + 1, a + m + 1, cmp);

    for(int l = 1; l <= m; ++l) {
        memset(tag, 0, sizeof(tag));
        int r = l;
        while(r + 1 <= m && a[r + 1].c == a[l].c)
            ++r;
        // a[l...r] 的 c 相同
        for(int i = l; i <= r; ++i) {
            tag[a[i].u] = true;
            tag[a[i].v] = true;
        }
        for(int i = l; i <= r; ++i) {
            if(tag[a[i].u]) {
                ++ans[a[i].u];
                tag[a[i].u] = false;
            }
            if(tag[a[i].v]) {
                ++ans[a[i].v];
                tag[a[i].v] = false;
            }
        }
    }

    int maxx = -1;

    for(int i = 1; i <= n; ++i) {
        maxx = max(maxx, ans[i]);
    }

    writeln(maxx);

    return 0;
}