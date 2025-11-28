#include <bits/stdc++.h>

#define N 1000010
#define int long long

using namespace std;

int n, k, c;
int a[N];

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

int diff[N];

bool check(int h) {
    memset(diff, 0, sizeof(diff));
    
    int tot = 0, cur = 0;
    
    for (int i = 1; i <= n; ++i) {
        cur += diff[i];
        int now = a[i] + cur;
        
        if (now < h) {
            int need = h - now;
            tot += need;
            
            if (tot > k) return 0;
            
            cur += need;
            if (i + c <= n) diff[i + c] -= need;
        }
    }
    
    return 1;
}

signed main() {
    n = read();
    k = read();
    c = read();
    
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
    }
    
    int l = 1, r = 2e9 + k;
    int ans = 0;
    
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    
    writeln(ans);
    
    return 0;
}