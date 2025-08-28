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

inline bool ok(int x,int y){
    int m = x>y?x:y;
    int n = x>y?y:x;
    return m <= 2*n + 2;
}

int main(){
    int t = read();
    for (int i = 0; i < t; i++) {
        int a = read();
        int b = read();
        int c = read();
        int d = read();
        int x1 = a;
        int y1 = b;
        int x2 = c - a;
        int y2 = d - b;
        if (ok(x1,y1) && ok(x2,y2)) puts("yes");
        else puts("no");
    }
    return 0;
}
