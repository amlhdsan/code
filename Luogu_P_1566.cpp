#include <bits/stdc++.h>

#define N 35

using namespace std;

int t, m;
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
    t = read();
    
    while(t--) {
        m = read();
        
        for(int i = 1; i <= m; ++i) {
            a[i] = read();
        }
        
        int ans = 0;
        
        for(int i = 1; i <= m; ++i) {
            bitset<30001> dp;
            dp[0] = 1;
            
            for(int j = 1; j <= m; ++j) {
                if(i != j) {
                    dp |= (dp << a[j]);
                }
            }
            
            if(dp[a[i]]) {
                ans++;
            }
        }
        
        writeln(ans);
    }
    
    return 0;
}