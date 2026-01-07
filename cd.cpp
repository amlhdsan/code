#include <bits/stdc++.h>

#define N 1005

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

struct P {
    int a, b;
} p[N];

struct BigInt {
    int d[5005], len;
    
    BigInt() {
        memset(d, 0, sizeof(d));
        len = 0;
    }
    
    void set(int x) {
        len = 0;
        while(x) {
            d[++len] = x % 10;
            x /= 10;
        }
        if(len == 0) len = 1;
    }
    
    void mul(int x) {
        int c = 0;
        for(int i = 1; i <= len; ++i) {
            c += d[i] * x;
            d[i] = c % 10;
            c /= 10;
        }
        while(c) {
            d[++len] = c % 10;
            c /= 10;
        }
    }
    
    void div(int x) {
        int r = 0;
        for(int i = len; i >= 1; --i) {
            r = r * 10 + d[i];
            d[i] = r / x;
            r %= x;
        }
        while(len > 1 && d[len] == 0) --len;
    }
    
    bool operator < (const BigInt &b) const {
        if(len != b.len) return len < b.len;
        for(int i = len; i >= 1; --i) {
            if(d[i] != b.d[i]) return d[i] < b.d[i];
        }
        return false;
    }
    
    void print() {
        for(int i = len; i >= 1; --i) {
            putchar(d[i] + '0');
        }
        putchar('\n');
    }
};

int n;
BigInt prod, tmp, ans;

bool cmp(P x, P y) {
    return x.a * x.b < y.a * y.b;
}

int main() {
    n = read();
    int ka = read(), kb = read();
    
    for(int i = 1; i <= n; ++i) {
        p[i].a = read();
        p[i].b = read();
    }
    
    sort(p + 1, p + n + 1, cmp);
    
    prod.set(ka);
    ans.set(0);
    
    for(int i = 1; i <= n; ++i) {
        tmp = prod;
        tmp.div(p[i].b);
        if(ans < tmp) ans = tmp;
        prod.mul(p[i].a);
    }
    
    ans.print();
    
    return 0;
}