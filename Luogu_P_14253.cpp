#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int T;
int n;
int a[N];
// int sum[N];
int maxx = 0;

inline void build(int p, int l, int r) {
    
}

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

inline void dfs(int p, int pre) {
    
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

signed main() {

    T = read();

    while(T--) {
        maxx = 1;
        int n = read();
        a[0] = 0;
        for(int i = 1; i <= n; ++i) {
            a[i] = read();
            a[i] += a[i - 1];
            // cout << a[i] << ' ';
        }
        a[0] = -0x7fffffff;
        sort(a + 1, a + 1 + n);
        int l = 1, r = 1;
        for(int i = 1; i <= n; ++i) {
            if(a[i] == a[i - 1]) {
                // forward_list
            }
            else {
                ++cnt;
            }
        }
        writeln(maxx);
    }

    return 0;
}