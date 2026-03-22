#include <bits/stdc++.h>

#define N 2010
#define MOD 100003
#define int long long

using namespace std;

int a, b, c, d, k;
int C[N][N];
int jc[N];

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

    a = read();
    b = read();
    c = read();
    d = read();
    k = read();

    for(int i = 0; i <= N - 1; ++i) {
        C[i][0] = C[i][i] = 1;
    }
    jc[0] = 1;
    for(int i = 1; i <= N - 1; ++i) {
        jc[i] = (jc[i - 1] * i) % MOD;
    }


    for(int i = 1; i <= N - 1; ++i) {
        for(int j = 1; j <= N - 1; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
    
    int ans = 0;

    for(int i = 0; i <= k; ++i) {
        ans = (ans + C[a][i] * C[b + d - (k  - i)][i] % MOD * jc[i] % MOD * C[c][k - i] * C[d][k - i] % MOD * jc[k - i]) % MOD;
    }

    writeln(ans);
    return 0;
}