#include <bits/stdc++.h>
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

    while(m--) {
        int op, l, r, k;
        op = read();
        if(op == 1) {
            l = read();
            r = read();
            k = read();
            mdf(1, 1, n, )
        }
        else {

        }
    }

    return 0;
}