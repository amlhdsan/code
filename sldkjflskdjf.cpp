#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, a[N];
int idx[N];

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

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        idx[a[i]] = i;
    }
    
    int l = n + 1, r = 0, ans = 0;

    for(int i = n; i >= n / 2; --i) {
        int len = r - l + 1;
        int lack, ll, rr;

        l = min(l, idx[i]);
        r = max(r, idx[i]);

        lack = (n - i) * 2 + 1 - len;
        
        if(lack >= 0) {
            ll = min(r + lack, n) - r;
            rr = l - max(l - lack, 1);
            ans += max(ll + rr - lack + 1, 0);
        }

        if(i == n)
            continue;

        lack = (n - i) * 2 - len;

        if(lack >= 0) {
            ll = min(r + lack, n) - r;
            rr = l - max(l - lack, 1);
            ans += max(ll + rr - lack + 1, 0);
        }
    }
    
    write(n * 2 + 1);
    putchar(' ');
    writeln(ans);
    
    return 0;
}