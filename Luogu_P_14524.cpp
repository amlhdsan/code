#include <bits/stdc++.h>

#define int long long
#define N 1000010

using namespace std;

int T;
int n;
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

signed main() {

    T = read();
    a[0] = 0x3f3f3f3f3f3f3f3f;

    while(T--) {
        n = read();

        for(int i = 1; i <= n; ++i) {
            a[i] = read();
        }
        int cnt = 0;
        bool flag = 0;
        for(int i = 2; i <= n; ++i) {
            if(a[i] > a[i - 1]) {
                ++cnt;
            }
            if(a[i] <= cnt) {
                puts("No");
                flag = 1;
                break;
            }
        }
        if(!flag) {
            puts("Yes");
        }
    }

    return 0;
}