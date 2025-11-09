#include <bits/stdc++.h>

#define N 1000010

using namespace std;

string str[N];

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
    int cnt = 0;
    while(cin >> str[++cnt]);

    sort(str + 1, str + 1 + cnt);

    int sum = 0;

    for(int i = 1; i <= cnt; ++i) {
        int t = 0;
        while(str[i][t] == str[i - 1][t] && t < str[i - 1].size())
            ++t;
        sum += str[i - 1].size() - t;
    }

    writeln(sum + 1);

    return 0;
}