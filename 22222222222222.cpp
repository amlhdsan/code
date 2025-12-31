#include <bits/stdc++.h>

#define int long long

using namespace std;

int T;

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
    
    while(T--) {
        int r = read();
        int q = read();
        int n = read();
        int m = read();
        
        int a = m / 3;
        int b = max(0LL, min(n, r - 1) - a);
        int c = q * b;
        
        int k = min(r - 1, r - 1 - c + c);
        
        if(r - 1 - c < m) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}