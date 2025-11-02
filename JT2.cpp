#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m;
int a[N];
int x;

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

    for(int i = 1; i <= n * m; ++i) {
        a[i] = read();
        a[i] = -a[i];
    }
    x = a[1];
    sort(a + 1, a + 1 + n * m);
    for(int i = 1; i <= n * m; ++i) {
        a[i] = -a[i];
    }
    int p = lower_bound(a + 1, a + n * m + 1, p) - a - 1;
    int t = p % m;
    write(p / m + 1);
    putchar(' ');
    if(t & 1) { // ji
        write(m - t + 1);
    }
    else {
        write(t);
    }
    return 0;
}