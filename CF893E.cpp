#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

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

inline void solve(int x, int y) {
    // x = p1^a1 * p2^a2 * ... * pk^ak

    // ans = \sum C_{a1 + y - 1}^{y - 1}
}

int main() {

    int T = read();

    while(T--) {
        int x = read();
        int y = read();
        solve(x, y);
    }

    return 0;
}
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

inline void solve(int x, int y) {
    // x = p1^a1 * p2^a2 * ... * pk^ak

    // ans = \sum C_{a1 + y - 1}^{y - 1}
}

int main() {

    int T = read();

    while(T--) {
        int x = read();
        int y = read();
        solve(x, y);
    }

    return 0;
}