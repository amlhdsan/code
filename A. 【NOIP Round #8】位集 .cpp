#include <bits/stdc++.h>

#define N 100010

using namespace std;

int n, m;

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

    n = read();
    m = read();

    int dp[n + 10][m + 10];
    int a[n + 10][m + 10];

    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        for(int j = 0; j < m; ++j) {
            a[i + 1][j + 1] = s[j] - '0';
        }
    }

    return 0;
}