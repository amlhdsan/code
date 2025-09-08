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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = read();
    vector<int> a(n + 1);
    int pos = 0;
    for(int i = 1; i <= n; i++) {
        a[i] = read();
        if(a[i] == n) pos = i;
    }
    
    vector<int> lmin(pos + 1), rmin(n + 2);
    lmin[pos] = a[pos];
    for(int i = pos - 1; i >= 1; i--) {
        lmin[i] = min(a[i], lmin[i + 1]);
    }
    
    rmin[pos] = a[pos];
    for(int j = pos + 1; j <= n; j++) {
        rmin[j] = min(a[j], rmin[j - 1]);
    }
    
    long long cnt = 0;
    for(int i = 1; i <= pos; i++) {
        int low = pos, high = n, best = pos - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            int X = n - (mid - i);
            int curMin = min(lmin[i], rmin[mid]);
            if(curMin >= X) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if(best >= pos) cnt += (best - pos + 1);
    }
    
    cout << (2LL * n + 1) << " " << cnt << "\n";
    return 0;
}