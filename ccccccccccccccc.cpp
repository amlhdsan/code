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

int main() {
    int n = read();
    vector<int> c(n + 2), p(n + 2);
    for (int i = 1; i <= n; i++) c[i] = read();
    for (int i = 1; i <= n; i++) p[i] = read();

    double f = 0;
    for (int i = n; i >= 1; i--) {
        double w = (100.0 - p[i]) / 100.0;
        f = max(f, c[i] + w * f);
    }

    printf("%.10f\n", f);
    return 0;
}