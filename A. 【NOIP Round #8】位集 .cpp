#include <bits/stdc++.h>
#define N 100010
#define ll long long
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
inline void write(ll x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
inline void writeln(ll x) {
    write(x);
    putchar('\n');
}
int n, m, Q;
ll X, Y, Z;
ll Ans, las;
int g[N];
int st[N], tp;
int ans[N][25];
int siz[N];
bool a[N][N];
int main() {
    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        static char s[N];
        scanf("%s", s + 1);
        for(int j = 1; j <= m; ++j) {
            a[i][j] = s[j] - '0';
        }
    }

    Q = read();
    X = read();
    Y = read();
    Z = read();

    for(int j = 1; j <= m; ++j) {
        g[j] = 1;
        st[++tp] = 1;
    }

    sort(st + 1, st + tp + 1);
    tp = unique(st + 1, st + tp + 1) - st - 1;

    for(int j = 1; j <= tp; ++j) {
        ans[1][j] = st[j];
    }
    siz[1] = tp;

    for(int i = 2; i <= n; ++i) {
        tp = 0;
        for(int j = 1; j <= m; ++j) {
            if(a[i][j] ^ a[i - 1][j]) {
                g[j] = i;
            }
            st[++tp] = g[j];
        }

        sort(st + 1, st + tp + 1);
        tp = unique(st + 1, st + tp + 1) - st - 1;

        for(int j = 1; j <= tp; ++j) {
            ans[i][j] = st[j];
        }
        siz[i] = tp;
    }

    int A = 1, B = n;
    for(int i = 1; i <= Q; ++i) {
        int l = min(A, B), r = max(A, B);
        las = upper_bound(ans[r] + 1, ans[r] + siz[r] + 1, l) - ans[r] - 1;
        A = (1ll * A * X + 1ll * las * Y + Z) % n + 1;
        B = (1ll * B * Y + 1ll * las * Z + X) % n + 1;
        Ans += las;
    }

    writeln(Ans);

    return 0;
}