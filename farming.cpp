#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n, tmp, ans;
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

inline int f(int a, int b) { // ceil(a / b)
    if(a % b == 0) {

    }
}

signed main() {

    n = read();
    for(int i = 0; i <= n; ++i) {
        mx[i] = -100000000000000000;
    }

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        s[i] = s[i - 1] + a[i];
        mx[i] = max(mx[i - 1], s[i]);
    }

    if(mx[n] == 0 || s[n] == 0) {
        writeln(n - 1);
        return 0;
    }

    if(mx[n] <= 0 || s[n] < 0) {
        writeln(-1);
        return 0;
    }

    ans = n - 1;

    for(int i = 1; i <= n; ++i) {
        if(s[i] + tmp <= 0) {

        }
    }

    return 0;
}