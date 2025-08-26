#include <bits/stdc++.h>

#define N 100010

using namespace std;

int T;
int n, k;
int a[N];

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
        k = read();
        for(int i = 1; i <= n; i++) {
            a[i] = read();
        }
        if(k % 2 == 0) {
            for(int i = 1; i <= n; i++) {
                if(a[i] % 3 == 1) {
                    a[i] += k;
                }
                else if(a[i] % 3 == 2) {
                    a[i] += 2 * k;
                }
            }
            puts("yes");
        }
        else {
            for(int i = 1; i <= n; i++) {
                if(a[i] % 2 == 0) {
                    puts("no");
                    goto end;
                }
            }
            puts("yes");
        }
    }

    return 0;
}