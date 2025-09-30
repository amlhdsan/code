#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n;
int a[N];
int s[N];
int mx[N];

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
    memset(mx, 0x3f, sizeof(mx));

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
    }

    return 0;
}