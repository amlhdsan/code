#include <bits/stdc++.h>

#define N 1000010
#define int long long
#define ls (p << 1)
#define rs (p << 1 | 1)

using namespace std;

int n;
int xx[N]; // 离散化 x

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

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        int a1, b1, a2, b2;
        a1 = read();
        b1 = read();
        a2 = read();
        b2 = read();
    }

    return 0;
}