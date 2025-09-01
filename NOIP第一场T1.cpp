#include <bits/stdc++.h>

#define N 1010
#define int long long

using namespace std;

int n, m, k, p;
int a[N][N];
int lsum[N], hsum[N];

int main() {

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    cin >> n >> m >> k >> p;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            lsum[j] += a[i][j];
            hsum[i] += a[i][j];
        }
    }

    if(p == 0) {
        int maxx = -0x7fffffff;
        for(int i = 1; i <= n; ++i) {
            maxx = max(maxx, hsum[i]);
        }
        for(int i = 1; i <= m; ++i) {
            maxx = max(maxx, lsum[i]);
        }
        cout << maxx * k << endl;
    }
    else if(n == 1 && m == 1) {
        cout << (a[1][1] + a[1][1] - (k - 1) * p) * k / 2 << endl;
    }

    return 0;
}