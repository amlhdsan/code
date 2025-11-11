// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int n, a[N];
char s[N];

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
    if(x < 0) {
        x = -x;
        putchar('-');
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + 48);
}

inline void writeln(int x) {
    write(x);
    putchar('\n');
}

int main() {
    n = read();
    for (int i = 0; i < n; i++) a[i] = read();
    s[0] = 'a';
    for (int i = 1; i < n; i++) {
        if (a[i]) s[i] = s[a[i] - 1];
        else s[i] = (s[i - 1] == 'a' ? 'b' : 'a');
    }
    for (int i = 0; i < n; i++) putchar(s[i]);
    putchar('\n');
    return 0;
}
