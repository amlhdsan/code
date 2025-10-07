#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4000005;
int n;
int x,y,z;
int *a;
int *ans;
int *st;
int top = 0;
int *L;
int *R;

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
    n = read();
    x = read(); y = read(); z = read();
    a = (int*)malloc((n+5)*sizeof(int));
    ans = (int*)malloc((n+5)*sizeof(int));
    st = (int*)malloc((n+5)*sizeof(int));
    L = (int*)malloc((n+5)*sizeof(int));
    R = (int*)malloc((n+5)*sizeof(int));
    a[0] = 0;
    for (int i = 1; i <= n; ++i) a[i] = ( (long long)a[i-1]*x + y ) % z;
    for (int i = 0; i <= n; ++i) ans[i] = INT_MAX;
    top = 0;
    for (int i = 1; i <= n; ++i) {
        while (top>0 && a[st[top-1]] <= a[i]) --top;
        L[i] = (top==0)?0:st[top-1];
        st[top++] = i;
    }
    top = 0;
    for (int i = n; i >= 1; --i) {
        while (top>0 && a[st[top-1]] < a[i]) --top;
        R[i] = (top==0)?(n+1):st[top-1];
        st[top++] = i;
    }
    for (int i = 1; i <= n; ++i) {
        int len = R[i] - L[i] - 1;
        if (a[i] < ans[len]) ans[len] = a[i];
    }
    for (int i = n-1; i >= 1; --i) if (ans[i+1] < ans[i]) ans[i] = ans[i+1];
    long long g = 0;
    for (int i = 1; i <= n; ++i) {
        int ai = ans[i];
        g = (g * x + ai + y) % z;
    }
    writeln((int)g);
    return 0;
}
