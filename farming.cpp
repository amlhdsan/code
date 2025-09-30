#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n, tmp, ans;
int a[N];
int s[N], ss[N];
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

inline int f(int a, int b) { // ceil(a / b)
    if(a % b == 0) {
        return a / b;
    }
    else {
        return (int)(a / b) + 1;
    }
}

signed main() {

    freopen("farming.in", "r", stdin);
    freopen("farming.out", "w", stdout);

    n = read();
    for(int i = 0; i <= n; ++i) {
        mx[i] = -100000000000000000;
    }

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
        ss[i] = ss[i - 1] + s[i];
        mx[i] = max(mx[i - 1], s[i]);
    }

    if(s[n] < 0) {
        writeln(-1);
        return 0;
    }

    ans = n;

    for(int i = 1; i <= n; ++i) {
        if(ss[i] + tmp < 0) {
            if(mx[i] <= 0) {
                writeln(-1);
                return 0;
            }
            ans += f(-(ss[i] + tmp), mx[i]);
            tmp += f(-(ss[i] + tmp), mx[i]) * mx[i];
        }
    }

    writeln(ans);

    return 0;
}