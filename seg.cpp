#include <bits/stdc++.h>
using namespace std;

namespace seg {

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l + r) >> 1)

    const int N = 2e5 + 10;
    int tree[N];
    int lazy[N];

    void build(int p, int l, int r) {

    }
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

    return 0;
}