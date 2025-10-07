#include <bits/stdc++.h>

#define N 100010
#define int long long

using namespace std;

int T;
int n;
int a[N];
int ans = 0;

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

inline bool cmp(int x, int y) {
    return x > y;
}

signed main() {

    T = read();

    while(T--) {
        ans = 0;
        n = read();
        for(int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        sort(a + 1, a + n + 1, cmp);
        for(int i = 1; i <= n; ++i) {
            ans += max(0, a[i] - i - 1);
        }
        writeln(ans);
    }

    return 0;
}