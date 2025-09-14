#include <bits/stdc++.h>
using namespace std;

int n;
int mp[1010][1010];
int mp1[1010][1010];
int mp2[1010][1010];

int ans1 = 0, ans2 = 0;

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

    int maxxx = -1, minnn = 0x7fffffff;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            mp[i][j] = read();
            maxxx = max(maxxx, mp[i][j]);
            minnn = min(minnn, mp[i][j]);
            mp1[i][j] = mp[i][j];
            mp2[i][j] = mp[i][j];
        }
    }

    if(maxxx == minnn) {
        write(1);
        putchar(' ');
        write(1);
        putchar('\n');
        return 0;
    }

    // mp1 : 山峰(周围设置为山谷)

    for(int i = 0; i <= n + 1; ++i) {
        mp1[0][i] = -1;
        mp1[n + 1][i] = -1;
        mp1[i][0] = -1;
        mp1[i][n + 1] = -1;
    }





    return 0;
}