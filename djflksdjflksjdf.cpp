#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

int n, k;

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

inline void solve() {
    n = read();
    k = read();
    int ans = 0;

    while(k > 0) {
        if(n == 1) {
            ans += k;
            break;
        }
        if(n == 2) {
            ans += 2 * k;
            break;
        }
        if(n == 3) {
            ans += k * 4;
            break;
        }
        else {
            int x = sqrt(n);

            while(x * x < n) {++x;}
            while((x - 1) * (x - 1) >= n) {--x;}
            
            if(x % 2 != n % 2) {++x;}

            ans += (x * x - n) / 2 + 1;
            n = x;
            --k;
        }
    }

    writeln(ans);
}

signed main() {
    int c = read();
    int T = read();

    while(T--) {
        solve();
    }

    return 0;
}