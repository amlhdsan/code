#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n, q;
int p[N];
int le[N], re[N];
char op[N], xx[N];

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

inline void work(int x) {
    
}

int main() {

    n = read();
    q = read();

    for(int i = 2; i <= n; ++i) {
        p[i] = read();
        ll[i] = read();
        rr[i] = read();
    }

    for(int i = 1; i <= n; ++i) {
        cin >> op[i];
        xx[i] = read();
    }

    while(q--) {
        int x = read();
        work(x);
    }

    return 0;
}