// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

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

int powmod(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (1LL * res * a) % MOD;
        a = (1LL * a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main() {
    int t = read();
    while (t--) {
        int n = read();
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = read();

        set<int> L, R;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mx) {
                L.insert(a[i]);
                mx = a[i];
            }
        }

        mx = 0;
        for (int i = n-1; i >= 0; i--) {
            if (a[i] > mx) {
                R.insert(a[i]);
                mx = a[i];
            }
        }

        int free_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (L.count(a[i]) == 0 && R.count(a[i]) == 0) free_cnt++;
        }

        writeln(powmod(2, free_cnt));
    }
    return 0;
}
