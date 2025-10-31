#include <bits/stdc++.h>

#define N 1000010

using namespace std;

int n, k;
int a[N];
int qmax[N], qmin[N];
int h = 0, t = -1;

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

inline void minn() {
    h = 0, t = -1;
    for(int i = 1; i <= n; ++i) {
        while(h <= t && a[qmin[t]] >= a[i]) 
            --t;
        qmin[++t] = i;
        if(qmin[h] <= i - k) 
            ++h;
        if(i >= k) {
            write(a[qmin[h]]);
            putchar(' ');
        }
    }
}

inline void maxx() {
    h = 0, t = -1;
    for(int i = 1; i <= n; ++i) {
        while(h <= t && a[qmax[t]] <= a[i]) {
            --t;
        }
        qmax[++t] = i;
        if(qmax[h] <= i - k) {
            ++h;
        }
        if(i >= k) {
            write(a[qmax[h]]);
            putchar(' ');
        }
    }
}

int main() {

    n = read();
    k = read();

    for(int i = 1; i <= n; ++i) {
        a[i] = read();
    }

    minn();
    puts("");
    maxx();

    return 0;
}