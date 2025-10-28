#include <bits/stdc++.h>

#define N 2000010

using namespace std;

int ans[N];
int n, m;

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

    for(int i = 1; i <= m; ++i) {
        
    }

    return 0;
}