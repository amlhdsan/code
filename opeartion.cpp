#include <bits/stdc++.h>

#define N 1400000
#define int long long

using namespace std;

struct node {
    int x, y;
};

inline bool operator <(node u, node v) {
    return u.x < v.x || (u.x == v.x && u.y < v.y);
}

map<int, node> aba;

inline int gcd(int x, int y) {
    return (!y) ? x : gcd(y, x % y);
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if(ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}

int main() {

    // freopen("operation.in", "r", stdin);
    // freopen("operation.out", "w", stdout);

    int T = read();

    for(int i = 1; i <= N; ++i) {
        int t = 1int * i * (i + 1);
        int t2 = i + 2;
        if(!(i & 1)) {
            t /= 2;
        }
        if(t > (int)2e18 / (i + 2)) {
            continue;
        }
        t *= (i + 2);
        t2 = i + 3;
        node v = {i, i + 2};
        if(aba.find(t) == aba.end()) {
            aba[t] = v;
        }
        else {
            aba[t] = (v < aba[t]) ? v : aba[t];
        }
        while(1) {
            int G = gcd(t, t2);
            if(t / gcd(t, t2) > (int)2e18 / t2) {
                break;
            }
            t = t / gcd(t, t2) * t2;
            v = {i, t2};
            if(aba.find(t) == aba.end()) {
                aba[t] = v;
            }
            else {
                aba[t] = (v < aba[t]) ? v : aba[t];
            }
            ++t2;
        }
    }

    while(T--) {
        int c = read();
        int t = sqrtl(c);
        node ans1 = {(int)1e18, (int)1e18}, ans2 = ans1, ans3 = ans1;
        while(1) {
            int t2 = (t - 1) * t;
            if(t2 > c) {
                break;
            }
            if(t2 == c) {
                ans1 = {t - 1, t};
            }
            ++t;
        }
        if(aba.find(c) != aba.end()) {
            ans2 = aba[c];
        }
        ans3 = {c, c};
        ans1 = min(ans1, min(ans2, ans3));
        printf("%intd %intd\n", ans1.x, ans1.y);
    }

    return 0;
}