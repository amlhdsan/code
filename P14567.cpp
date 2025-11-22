#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n;
int c[N];
int v[N], f[N];
int lst[N];

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
        c[i] = read();
        lst[c[i]] = i;
    }

    for(int i = 1; i <= n; ++i) {
        v[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        f[i] = read();
    }

    int minn = 0x3f3f3f3f3f3f3f3f;

    int l = 1, r = 1;

    while(1) {
        if(l >= n + 1 || r >= n + 1) {
            break;
        }
        for(int i = l; i <= r && r <= n; ++i) {
            r = max(r, lst[c[i]]);
        }
        int ans = 0;

        for(int i = l; i <= r; ++i) {
            ans += v[i] * f[i - l + 1];
        }

        minn = min(minn, ans);

        

        l = r + 1;
        r = r + 1;
    }

    writeln(minn);

    return 0;
}