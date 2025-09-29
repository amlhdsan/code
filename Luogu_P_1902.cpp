#include <bits/stdc++.h>
using namespace std;

int n, m, mx = -1;
int p[1010][1010];
bool iff[1010][1010];

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

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

inline bool dfs(int x, int y, int px, int py) {
    if(x == n && y == m) {
        return true;
    }

    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && !iff[nx][ny]) {
            iff[nx][ny] = true;
            if(dfs(nx, ny, x, y)) return true;
        }
    }
    return false;
}

inline void solve(int x, int y) {
    
}

inline bool check(int x) {
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            iff[i][j] = (p[i][j] <= x);
        }
    }

    return dfs(1, 1);
}

inline void dpp() {
    
}

int main() {

    n = read();
    m = read();

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            p[i][j] = read();
            mx = max(mx, p[i][j]);
        }
    }

    int l = 1, r = mx, ans;

    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }


    return 0;
}