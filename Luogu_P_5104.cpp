#include <bits/stdc++.h>

#define int long long
#define MOD 1000000007

using namespace std; 

int w, n, k;

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

inline int qpow(int a, int b) {
    int ret = 1;
    while(b) {
        if(b & 1) {
            ret = ret * a % MOD;
        }
        a  = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

signed main() {

    w = read(); 
    n = read();
    k = read();

    writeln(w * qpow(qpow(2, k), MOD - 2) % MOD);

    return 0;
}