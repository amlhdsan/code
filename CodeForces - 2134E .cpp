#include <bits/stdc++.h>

#define N 1010

using namespace std;

int T;
int n;
int d[N];
int a[N];
bool tag[N];

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
        d[n + 1] = d[n + 2] = 0;
        for(int i = n; i >= 1; --i) {
            cout << "throw " << i << endl;
            d[i] = read();
        }

        for(int i = 1; i <= n - 1; ++i) {
            if(d[i] != d[i + 1]) {
                if(d[i] == d[i + 1] + 1) {
                    a[i] = 1;
                }
                else {
                    a[i] = 2;
                }
            }
            else {

            }
        }
        fflush(stdout);
    }

    return 0;
}