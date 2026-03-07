#include <bits/stdc++.h>

#define N 250010

using namespace std;

int n;
string str;
bool tag[N];

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

    n = read();
    cin >> str;

    str = " " + str;

    for(int i = 1; i <= n - 1; ++i) {
        if(str[i] == str[i + 1]) {
            tag[i] = 1;
        }
        if(str[i] == 'R' && str[i + 1] == 'V' || str[i] == 'V' && str[i + 1] == 'R') {
            tag[i] = 1;
        }
        if(str[i] == 'B' && str[i + 1] == 'V' || str[i] == 'V' && str[i + 1] == 'B') {
            tag[i] = 1;
        }
    }

    int maxx = 0;
    int nl = 0;

    for(int i = 1; i <= n; ++i) {
        if(tag[i] == 0) {
            ++nl;
        }
        else {
            maxx = max(maxx, nl);
            nl = 0;
        }
    }

    writeln(maxx + 1);

    return 0;
}