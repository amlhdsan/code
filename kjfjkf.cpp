#include <bits/stdc++.h>

#define N 100010
#define int long long

using namespace std;

int n;
int p[N];
int P = 1;

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

inline int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

inline int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

signed main() {

    n = read();

    for(int i = 1; i <= n; ++i) {
        p[i] = read();
        P = lcm(P, p[i]);
    }

    writeln(P);

    return 0;
}