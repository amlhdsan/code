#include <bits/stdc++.h>
using namespace std;

int T;
string str;

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

    ios::sync_with_stdio(flase);
    cin.tie(0);
    cout.tie(0);

    T = read();

    while(T--) {
        cin >> str;
        str = " " + str;
        int n = str.size() - 1;
        for(int i = 1; i <= n; ++i) {
            if(str[i] != str[1]) {
                writeln(2 * n - i + 1);
            }
        }
    }

    return 0;
}