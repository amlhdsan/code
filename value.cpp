#include <bits/stdc++.h>

#define N 10000010
#define int long long

using namespace std;

int n;
int x, y, z;
int a[N];
int f[N];

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

inline void gen() {
    for(int i = 1; i <= n; ++i) {
        a[i] = (a[i - 1] * x + y) % z;
    }
}

inline void output() {
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans = (ans * x + f[i] + y) % z;
    }
    writeln(ans);
}

signed main() {

    n = read();
    x = read(), y = read(), z = read();

    gen();

    

    output();

    return 0;
}