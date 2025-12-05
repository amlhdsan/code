#include <bits/stdc++.h>

#define N 20

using namespace std;

int k, n;
int p[N];
int s[N];
double dp[110][80000];

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

    k = read();
    n = read();

    for(int i = 1; i <= n; ++i) {
        p[i] = read();
        int x;
        while(x = read()) {
            s[i] |= (1 << (x - 1));
        }
    }

    for(int i = 1; i <= k; ++i) {
        for(int S = 0; S <= (1 << n) - 1; ++S) {
            for(int j = 1; j <= n; ++j) {
                if((s[j] & S) != s[j]) 
                    dp[i][S] += dp[i - 1][S];
                else 
                    dp[i][S] += max(dp[i - 1][S], p[j] + dp[i - 1][S | 1 << j]);
            }
            dp[i][S] /= n * 1.0;
        }
    }

    printf("%.6lf", dp[k][1]);

    return 0;
}