#include <bits/stdc++.h>

#define N 110

using namespace std;

int n, q;
double dp1[N];
double dp2[N][N];

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

    q = read();
    n = read();

    if(q == 1) {
        for(int i = 2; i <= n; ++i) {
            dp1[i] = dp1[i - 1] + 2.0 / i;
        }
        printf("%.6lf", dp1[n]);
    }

    else {
        for(int i = 1; i <= n; ++i) {
            dp2[i][0] = 1;
        }

        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j <= i - 1; ++j) {
                for(int k = 1; k <= i - 1; ++k) {
                    dp2[i][j] += dp2[k][j - 1] + dp2[i - k][j - 1] - dp2[k][j - 1] * dp2[i - k][j - 1];
                }
                dp2[i][j] /= (i - 1) * 1.0;
            }
        }

        double ans = 0;

        for(int i = 1; i <= n; ++i) {
            ans += dp2[n][i];
        }

        printf("%.6lf", ans);
    }

    return 0;
}