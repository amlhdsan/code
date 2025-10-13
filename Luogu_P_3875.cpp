#include <bits/stdc++.h>

#define N 400010
using namespace std;

int n;
int xx[N], xxx = 0;

struct linee {
    int l, r;
    int h;
    int tag;
}line;

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

    for(int i = 1; i <= n; ++i) {
        int s, d, f, g;
        int x1, y1, x2, y2;
        s = read();
        d = read();
        f = read();
        g = read();
        if(s == f) { // 平行于 y 轴
            if(d > g) {
                swap(d, g);
            }
            x1 = 
        }
    }

    return 0;
}