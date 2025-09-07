#include <bits/stdc++.h>

using namespace std;

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

void solve(int cur, int steps) {
    if (steps == 0) {
        writeln(cur);
        return;
    }
    
    solve(cur * 2, steps - 1);
    
    if ((cur - 1) % 3 == 0 && cur > 1) {
        int prev = (cur - 1) / 3;
        if (prev % 2 == 1) {
            solve(prev, steps - 1);
        }
    }
}

int main() {
    int t = read();
    
    while (t--) {
        int k = read();
        int x = read();
        
        solve(x, k);
    }
    
    return 0;
}