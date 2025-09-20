#include <bits/stdc++.h>

#define N 200010
#define M 200010

using namespace std;

int n, m, s;
int l[M], r[M];

struct node {
    int w, v;
}a[N];

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

inline void calsum(int W) {

}

int main() {

    n = read();
    m = read();
    s = read();

    for(int i = 1; i <= n; ++i) {
        a[i].w = read();
        a[i].v = read();
    }

    for(int i = 1; i <= n; ++i) {
        l[i] = read();
        r[i] = read();
    }

    int l = 0, r = 1000000, mid, ans;

    while(l < r) {
        mid = (l + r) >> 1;
        int y = caly(mid);
        if(y > s)
            r = mid;
        else
            l = mid + 1;
    }

    for(int i = 1; i <= n; ++i) {
        
    }

    while(l < r) {
        mid = (l + r) >> 1;
        int y = caly(mid); // 判定函数
        if(y > s)
            r = mid;
        else
            l = mid + 1;
    }



    return 0;
}