#include <bits/stdc++.h>
using namespace std;

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

    double ans = 0;

    for(int i = 1; i <= 2027; ++i) {
        ans += 2.0 / i;
    }

    printf("%.6lf", ans);

    return 0;
}