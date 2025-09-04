// 電影發明以後，人類的生命，比以前至少延長了三倍。
// amlhdsan
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

const int S = 300005;

int ch[S][2], fail[S], tag[S], col[S], q[S];
int tot;
char s[S];

void ins(char *t) {
    int u = 0;
    for (int i = 0; t[i]; i++) {
        int c = t[i] - '0';
        if (!ch[u][c]) ch[u][c] = ++tot;
        u = ch[u][c];
    }
    tag[u] = 1;
}

void build() {
    int l = 0, r = 0;
    for (int c = 0; c < 2; c++) {
        int v = ch[0][c];
        if (v) q[r++] = v;
    }
    while (l < r) {
        int u = q[l++];
        for (int c = 0; c < 2; c++) {
            int v = ch[u][c];
            if (v) {
                fail[v] = ch[fail[u]][c];
                tag[v] |= tag[fail[v]];
                q[r++] = v;
            } else ch[u][c] = ch[fail[u]][c];
        }
    }
}

bool dfs(int u) {
    if (tag[u]) return false;
    col[u] = 1;
    for (int c = 0; c < 2; c++) {
        int v = ch[u][c];
        if (tag[v]) continue;
        if (col[v] == 1) return true;
        if (!col[v] && dfs(v)) return true;
    }
    col[u] = 2;
    return false;
}

int main() {
    int n = read();
    for (int i = 0; i < 2; i++) ch[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        ins(s);
        if(i == n) {
            
        }
    }
    build();
    puts(dfs(0) ? "TAK" : "NIE");
    return 0;
}