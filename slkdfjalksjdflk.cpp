#include <bits/stdc++.h>
#define int long long
using namespace std;

int T;
int a, b;

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
    T = read();
    while(T--) {
        a = read();
        b = read();
        if(b % 3 == 0) writeln(2LL * (a / b));
        else if(b % 3 == 1) writeln(2LL * (a / b) + (2LL * a % b) / b);
        else writeln(2LL * (a / b) + (2LL * a % b + 2) / b);