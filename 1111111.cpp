#include <bits/stdc++.h>

#define N 400010

using namespace std;

int n, m;
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

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    sort(a + 1, a + 1 + n);

    int mx = a[n];

    int ans = 0;

    for(int i = 1; i <= n; ++i) {
        if((mx - a[i]) % m == 0) {
            ans = max(ans, (mx - a[i]) / m);
        }
        else {
            ans = max((mx - a[i]) / m + 1, ans);
            // ans += 1;
        }
    }

    writeln(ans);

    return 0;
}