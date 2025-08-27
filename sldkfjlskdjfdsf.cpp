// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

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

const int N = 2000005;
int a[N];

int main() {
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    int tot2 = 0;
    for (int i = 1; i <= n; i++) if (a[i] == 2) tot2++;

    int pref1 = 0, pref2 = 0;
    int D = 0, minD = 0, G = 0, ans = tot2;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) pref1++; else pref2++;
        D = pref2 - pref1;
        if (D - minD > G) G = D - minD;
        if (D < minD) minD = D;
        int cur = tot2 - D + G;
        if (cur > ans) ans = cur;
    }
    writeln(ans);
    return 0;
}
