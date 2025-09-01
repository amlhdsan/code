#include<bits/stdc++.h>

#define int long long 
#define N 100010

using namespace std;

int pr[10] = {2,3,5,7,11,13,17,19,23,29};
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

inline int mpow(int a, int b, int m) {
    int r = 1 % m;
    a %= m;
    while (b) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}

inline void solve() {
    int n = read();
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) a[i] = read();
    int p = -1;
    for (int i = 0; i < 10; i++) {
        if (pr[i] <= k + 1 && k % pr[i]) {
            p = pr[i];
            break;
        }
    }
    if (p == -1) p = 2;
    int kp = k % p, inv = 1;
    if (kp) inv = mpow(kp, p - 2, p);
    for (int i = 0; i < n; i++) {
        int r = a[i] % p;
        int nd = kp ? ((int)(p - r) % p * inv % p) : 0;
        a[i] += 1int * nd * k;
    }
    for (int i = 0; i < n; i++) {
        write(a[i]);
        if (i == n - 1) putchar('\n');
        else putchar(' ');
    }
    return;
}

int main() {
    int t = read();
    while (t--) solve();
    return 0;
}
