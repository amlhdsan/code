#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;

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

inline int eulerphi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

inline int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {

    freopen("AAAAoutput.cpp", "w", stdout);

    int cnt = 0;

    for(n = 1; n <= 10000; ++n) {
        int x = 0, y = 0;

        for(int i = 1; i <= n; ++i) {
            x += gcd(i, n);
            if(n % i == 0) 
                y += i * eulerphi(i);
        }

        if(x * y >= n * n * n) {
            cout << (1.0 * 1.0 * x * 1.0 * y / (1.0 * n * n * n)) << endl;
        }
    }

    // writeln(cnt);

    return 0;
}