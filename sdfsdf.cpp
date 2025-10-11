#include <bits/stdc++.h>

#define N 100010

using namespace std;

int T;
int n;
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

inline void solve() {
    n = read();
    int minn = 0x7fffffff;
    int cnt = 0;
    string str;
    cin >> str;
    for(int i = 1; i <= n; ++i) {
        if(str[i - 1] == '(') {
            a[i] = 1;
        }
        else {
            a[i] = -1;
        }
        cnt += a[i];
        if(cnt <= -2) {
            puts("No");
            return;
        }
    }
    if(cnt != 0) {
        puts("No");
        return;
    }
    puts("Yes");
}

int main() {
    T = read();
    while(T--) {
        solve();
    }

    return 0;
}