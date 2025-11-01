#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, m;
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

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    while(m--) {
        int x = read();
        int l = 1, r = n, ans = 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(a[mid] >= x) { // 满足条件的第一个
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        if(x >= a[n]) {
            ans = -1;
        }
        writeln(a[ans]);
    }

    return 0;
}