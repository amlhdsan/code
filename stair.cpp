#include <bits/stdc++.h>

#define N 200005
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

struct Node {
    int id, a, b;
    ll d;
} p[N];

int n, m;
int a[N], b[N], s[N];

bool cmp(Node x, Node y) {
    return x.d < y.d;
}

int main() {
    n = read();
    m = 2 * n;
    
    for(int i = 1; i <= m; ++i) a[i] = read();
    for(int i = 1; i <= m; ++i) b[i] = read();
    
    for(int i = 1; i <= m; ++i) {
        p[i].id = i;
        p[i].a = a[i];
        p[i].b = b[i];
        p[i].d = (ll)a[i] - b[i];
    }
    
    sort(p + 1, p + m + 1, cmp);
    
    for(int i = 1; i <= n; ++i) {
        s[p[i].id] = 0;
    }
    for(int i = n + 1; i <= m; ++i) {
        s[p[i].id] = 1;
    }
    
    ll ans = 0;
    int cu = 0, cd = 0;
    
    for(int i = 1; i <= m; ++i) {
        if(s[i] == 0) {
            ans += (ll)a[i] * (n - cu);
            cu++;
        } else {
            ans += (ll)b[i] * (n - cd);
            cd++;
        }
    }
    
    writeln(ans);
    for(int i = 1; i <= m; ++i) {
        write(s[i]);
        if(i < m) putchar(' ');
    }
    putchar('\n');
    
    return 0;
}