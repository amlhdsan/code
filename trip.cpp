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

int n, q;
set<int> s;

int main() {
    freopen("trip.in", "r", stdin);
    freopen("trip.out", "w", stdout);
    n = read();
    q = read();
    while (q--) {
        char op;
        cin >> op;
        int x, y, ans = 0;
        if (op == '-') {
            x = read();
            s.insert(x);
        } else if (op == '+') {
            x = read();
            s.erase(x);
        } else {
            x = read();
            y = read();
            if (s.empty()) {
                puts("possible");
                continue;
            }
            if (x > y) swap(x, y);
            auto it = s.lower_bound(x);
            if (it == s.end() || *it > y) ans = 1;
            it = s.lower_bound(y);
            if (it == s.end() && *s.begin() > x) ans = 1;
            puts(ans ? "possible" : "impossible");
        }
    }
    return 0;
}
