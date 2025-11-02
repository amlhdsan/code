#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, k, q;
int a[N];
int c[N], cnttt = 0;
int tmpb[N], tmpc[N];

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
    k = read();
    q = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    for(int i = 1; i <= k; ++i) {
        tmpb[i] = read();
    }

    for(int i = 1; i <= k; ++i) {
        tmpc[i] = read();
    }

    for(int i = 1; i <= k; ++i) {
        for(int j = 1; j <= tmpb[i]; ++j)
            c[++cnttt] = tmpc[i];
    }

    sort(c + 1, c + n + 1);

    return 0;
}