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

inline void writeLL(long long x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) writeLL(x / 10);
    putchar(x % 10 + '0');
}

int main() {
    int T = read();
    while (T--) {
        int n = read();
        int m = read();
        vector<string> A(n), B(m);
        for (int i = 0; i < n; ++i) {
            static char buf[200005];
            if(scanf("%s", buf)!=1) buf[0]=0;
            A[i] = string(buf);
        }
        for (int j = 0; j < m; ++j) {
            static char buf[200005];
            if(scanf("%s", buf)!=1) buf[0]=0;
            B[j] = string(buf);
        }
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                string s = A[i] + B[j];
                int L = (int)s.size();
                vector<int> d(L);
                for (int k = 0; k < L; ++k) {
                    int l = k - 1;
                    int r = k + 1;
                    int cnt = 1;
                    while (l >= 0 && r < L && s[l] == s[r]) {
                        --l; ++r; ++cnt;
                    }
                    d[k] = cnt;
                    int a = k - 1, b = k + 1;
                    int mirror = 1;
                    while (a >= 0) {
                        int needL = a - (d[a] - 1);
                        int needR = b + (d[a] - 1);
                        if (needL < 0 || needR >= L) break;
                        bool ok = true;
                        for (int p = 0; p < d[a]; ++p) {
                            if (s[a - p] != s[b + p]) { ok = false; break; }
                        }
                        if (!ok) break;
                        d[k] += d[a];
                        a -= d[a];
                        b += d[a];
                    }
                }
                for (int v : d) ans += v;
            }
        }
        writeLL(ans);
        putchar('\n');
    }
    return 0;
}
