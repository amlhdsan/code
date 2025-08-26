#include <bits/stdc++.h>
using namespace std;

int T;
int n, a, b;

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

    T = read();
    while(T--) {
        n = read();
        a = read();
        b = read();
        if(n % 2 == 0) {
            if(b >= a) {
                if(b % 2 == 0) {
                    puts("yes");
                }
                else {
                    puts("no");
                }
            }
            else {
                if(a % 2 == 0 && b % 2 == 0) {
                    puts("yes");
                }
                else {
                    puts("no");
                }
            }
        }
    }

    return 0;
}