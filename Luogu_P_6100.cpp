#include <bits/stdc++.h>

#define N 210

using namespace std;

int n, k;
int c[N][N];
int a[N][N];
int d[N][N];

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

inline void add(int x1, int y1, int x2, int y2, int x) {
    c[x1][y1] += x;
    c[x2 + 1][y1] -= x;
    c[x1][y2 + 1] -= x;
    c[x2 + 1][y2 + 1] += x;
    return;
}

int main() {

    n = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        int x1 = read(), y1 = read(), x2 = read(), y2 = read();
        add(x1 + 1, y1 + 1, x2, y2, 1);
    }

    for(int i = 0; i <= 200; ++i) {
        for(int j = 0; j <= 200; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + c[i][j];
        }
    }

    for(int i = 0; i <= 200; ++i) {
        for(int j = 0; j <= 200; ++j) {
            if(a[i][j] == k) {
                d[i][j] = -1;
            }
            else if(a[i][j] == j - 1) {
                d[i][j] = 1;
            }
            // write(a[i][j]);
            // putchar(' ');
        }
        // puts("");
    }

    

    return 0;
}