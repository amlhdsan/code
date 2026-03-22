/*
### 問題文

`0` と `1` からなる長さ $N$ の文字列 $A,B$ が与えられます．$A$ の $i$ 文字目を $A_i$ とします．

あなたは以下の操作を $0$ 回以上好きな回数行うことができます．

-   $A_{i-1}=A_{i+1}$ を満たす整数 $i\ (2\leq i\leq N-1)$ を選び，$A_i$ を反転する（`1` ならば `0` に，`0` ならば `1` にする）．

操作を繰り返すことで $A$ を $B$ に一致させることができるか判定し，可能ならば一致させるために必要な操作回数の最小値を求めてください．

$T$ 個のテストケースが与えられるので，それぞれについて答えを求めてください．
*/


#include <bits/stdc++.h>
using namespace std;

int n;

string a, b;

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

inline void solve() {
    n = read();
    cin >> a >> b;

    int ans = 0;

    for (int i = 1; i < n - 1; i++) {
        if (a[i] != b[i] && a[i - 1] == a[i + 1]) {
            swap(a[i], a[i + 1]);
            ans++;
        }
    }

    if (a == b) writeln(ans);
    else writeln(-1);
}

int main() {

    int T = read();

    while(T--) {
        solve();
    }

    return 0;
}