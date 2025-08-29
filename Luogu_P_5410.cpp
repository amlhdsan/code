#include <bits/stdc++.h>

#define N 20000010

using namespace std;

string a;
int n;
int z[N];

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

inline void z_a() {
    memset(z, 0, sizeof(z));
    z[1] = n;

    for(int i = 2, l = 0, r = 0; i <= n; ++i) {
        if(i <= r) {
            z[i] = min(z[i - l + 1], r - i + 1);
        }
        while(i + z[i] <= n && a[z[i] + 1] == a[i + z[i]]) {
            ++z[i];
        }
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a;
    a = " " + a;
    n = a.size() - 1;

    z_a();

    int ans1 = 0;

    for(int i = 1; i <= n; ++i) {
        ans1 ^= (i * (z[i] + 1));
    }

    writeln(ans1);
    return 0;
}