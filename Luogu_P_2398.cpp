#include <bits/stdc++.h>
using namespace std;

#define N 100010

bool pri[N];

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

inline void init(int x) {
    memset(pri, true, sizeof(pri));
    pri[0] = pri[1] = false;
    for (int i = 2; i * i <= x; i++) {
        if (pri[i]) {
            for (int j = i * i; j <= x; j += i) {
                pri[j] = false;
            }
        }
    }
    return;
}

inline int phi(int x) {
    int ans = x;
    for (int i = 2; i * i <= x; i++) {
        if (pri[i] && x % i == 0) {
            ans = ans / i * (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        ans = ans / x * (x - 1);
    }
    return ans;                  
}

inline void solve(int x) {
    int ans = 0;
    for(int i = 1; i <= x; ++i) {
        ans += ((int) x / i) ^ 2 * phi(i);
    }
    writeln(ans);
    return;   
}

int main() {

    int n = read();

    init(n);

    solve(n);

    return 0;
}