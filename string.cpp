#include <bits/stdc++.h>
using namespace std;

int T;
// string str;

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

    // freopen("string.in", "r", stdin);
    // freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    T = read();

    while(T--) {
        string str;
        cin >> str;
        bool flag = 0;
        int n = str.size();
        str = " " + str;
        for(int i = 2; i <= n; ++i) {
            if(str[i] != str[1]) {
                writeln(2 * n - i + 1);
                flag = 1;
                break;
            }
        }
        if(!flag)
            writeln(n - 1);
    }

    return 0;
}