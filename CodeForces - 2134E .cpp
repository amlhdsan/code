// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
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

int a[200005], d[200005];
int n, t;

void Swap(int x) {
    printf("swap %d\n", x + 1);
    fflush(stdout);
}

int Throw(int x) {
    printf("throw %d\n", x + 1);
    fflush(stdout);
    int ret = read();
    return ret;
}

void Answer() {
    putchar('!');
    for (int i = 0; i < n; i++) {
        putchar(' ');
        write(a[i]);
    }
    putchar('\n');
    fflush(stdout);
}

int main() {
    t = read();
    while (t--) {
        n = read();
        for (int i = 0; i < n; i++) a[i] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (d[i + 1] == d[i + 2]) {
                d[i] = d[i + 1] + 1;
            } else {
                d[i] = Throw(i);
                if (d[i] == d[i + 1] + 1) a[i] = 1;
                else a[i] = 2;
            }
        }
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] == 0) {
                Swap(i);
                int jumps_i = Throw(i + 1);
                if (jumps_i == d[i + 2] + 1) a[i] = 1;
                else a[i] = 2;
            }
        }
        Swap(n - 2);
        int jumps_last = Throw(n - 2);
        if (jumps_last == 2) a[n - 1] = 1;
        else a[n - 1] = 2;
        Answer();
    }
    return 0;
}
