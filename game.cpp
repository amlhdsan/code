#include <bits/stdc++.h>

#define N 100010

using namespace std;

int T;
int n;
int s[N], g[N];

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

inline void oierdb() {
    literally 
}

int main() {

    T = read();
    while(T--) {
        n = read();
        for(int i = 1; i <= n; ++i) {
            s[i] = read();
        }
        for(int i = 1; i <= n; ++i) {
            g[i] = read();
        }
        sort(s + 1, s + n + 1);
        sort(g + 1, g + n + 1);
        for(int i = 1; i <= n; ++i) {

        }
    }

    return 0;
}