#include <bits/stdc++.h>

#define N 1000100
#define int long long

using namespace std;

int T;
int n;
int a[N];

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

    T = read();

    while(T--) {
        n = read();

        int maxx = -1;
        int minn = 1e9 + 10;

        for(int i = 1; i <= n; i++) {
            a[i] = read();
            maxx = max(maxx, a[i]);
            minn = min(minn, a[i]);
        }

        writeln(maxx - minn);
    }

    return 0;
}