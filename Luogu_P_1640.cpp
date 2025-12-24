#include <bits/stdc++.h>

#define N 1000010
#define M 10010

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

int n;
int a[N], b[N];
int mat[M];
bool vis[M];

bool dfs(int val) {
    for(int i = 1; i <= n; ++i) {
        if((a[i] == val || b[i] == val) && !vis[i]) {
            vis[i] = true;
            int nxt = (a[i] == val ? b[i] : a[i]);
            if(!mat[nxt] || dfs(nxt)) {
                mat[nxt] = i;
                return true;
            }
        }
    }
    return false;
}

int main() {
    n = read();
    
    for(int i = 1; i <= n; ++i) {
        a[i] = read();
        b[i] = read();
    }
    
    int ans = 0;
    for(int val = 1; val <= 10000; ++val) {
        memset(vis, 0, sizeof(vis));
        if(dfs(val)) {
            ans = val;
        } else {
            break;
        }
        
    }
    
    writeln(ans);
    
    return 0;
}