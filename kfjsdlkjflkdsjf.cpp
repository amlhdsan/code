// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
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

int main() {
    int t = read();
    while (t--) {
        int n = read();
        vector<int> p(n+1);
        bool hasZero = false;
        for (int i = 1; i <= n; i++) {
            p[i] = read();
            if (p[i] == 0) hasZero = true;
        }
        bool sorted = true;
        for (int i = 1; i <= n; i++) {
            if (p[i] != i) {
                sorted = false;
                break;
            }
        }
        if (!hasZero && sorted) writeln(0);
        else writeln(n);
    }
    return 0;
}
