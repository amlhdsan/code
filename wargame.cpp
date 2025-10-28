#include <bits/stdc++.h>

#define N 1010

using namespace std;

int n, m;
int mp[N][N];
int cnt1, cnt2;

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
    
    // freopen("wargame.in", "r", stdin);
    // freopen("wargame.out", "w", stdout);

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            mp[i][j] = read();
            if(mp[i][j] == 1)
                ++cnt1;
        }
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m - 1; ++j) {
            if(mp[i][j] == mp[i][j + 1] && mp[i][j] == 1)
                ++cnt2;
        }
    }
    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n - 1; ++i) {
            if(mp[i][j] == mp[i + 1][j] && mp[i][j] == 1)
                ++cnt2;
        }
    }

    writeln(cnt1 + cnt2);

    return 0;
}