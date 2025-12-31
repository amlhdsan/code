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
        
        int lim = m / 3;
        int pos = r - 1;
        int skp = 0;
        
        if(n > lim && q > 0) {
            int per = n - lim;
            int ful = min(pos / n, q);
            skp += ful * per;
            
            int rem = pos - ful * n;
            int rst = q - ful;
            
            if(rst > 0 && rem > lim) {
                skp += rem - lim;
            }
        }
        
        int adm = pos - skp;
        
        if(adm < m) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    
    return 0;
}