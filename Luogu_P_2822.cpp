#include <bits/stdc++.h>

#define N 2010

using namespace std;

int C[N][N];
int n, m, k;
int ans[N][N]; // 表示 i, j 范围内的答案.

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

inline void init() {
    C[0][0] = 1;

    for(int i = 1; i <= 2000; ++i) {
        C[i][0] = 1;
        for(int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % k;
        }
    }

    for(int i = 1; i <= 2000; ++i) {
        for(int j = 1; j <= i; ++j) {
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1];
            if(C[i][j] % k == 0) {
                ++ans[i][j];
            }
        }
        ans[i][i + 1] = ans[i][i];
    }
}

int main() {

    int t;

    t = read();
    k = read();

    init();

    while(t--) {
        n = read();
        m = read();
        // k = read();
        writeln(m > n ? ans[n][n] : ans[n][m]);
    }
    return 0;
}