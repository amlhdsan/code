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

        for(int i = 1; i <= n; i++) {
            a[i] = read();
        }

        sort(a + 1, a + 1 + n);

        int ans = -1;

        for(int i = 2; i <= n; ++i) {
            if(a[i] != a[i - 1])
                ans = max(ans, a[i - 1] - (a[i] - a[i - 1] - 1));
        }

        ans = max(ans, a[n] - a[1]);

        writeln(ans);
    }

    return 0;
}