// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
#include <bits/stdc++.h>
#define N 2000010
#define int long long
using namespace std;



int n;
char s[N];
int las[N], cnt[N];

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

signed main() {

    n = read();
    for(int i = 1; i <= n; ++i) {
        cin >> s[i];
    }

    int res = 0;

    for(int i = 1; i <= n; ++i) {
        int j = i - 1;
        while(j > 0) {
            if(s[j] == s[i]) break;
            j = las[j] - 1;
        }
        if(j <= 0) {
            las[i] = 0;
        } else {
            las[i] = j;
            cnt[i] = cnt[j - 1] + 1;
            res += cnt[i];
        }
    }

    writeln(res);
    return 0;
}
