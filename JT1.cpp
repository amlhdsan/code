#include <bits/stdc++.h>
using namespace std;

string str;
int n = 0;
int k[10];

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

    cin >> str;

    n = str.size();
    str = " " + str;

    for(int i = 1; i <= n; ++i) {
        if(str[i] <= '9' && str[i] >= '0') {
            ++k[str[i] - '8'];
        }
    }
    for(int i = 9; i >= 0; --i) {
        while(k[i] > 0) {
            write(i);
            --k[i];
        }
    }

    return 0;
}