#include <bits/stdc++.h>
using namespace std;

int phi[40010];

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

inline void init(int n) {
    for (int i = 1; i <= n; i++) 
        phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) {
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
    return;
}

inline void solve(int n) {
    int ans = 2;
    for(int i = 1; i <= n; i++) {
        ans += phi[i] * 2;
    }
    writeln(ans);
    return;
}

int main() {

    int n = read();

    init(n);

    solve(n);

    return 0;
}