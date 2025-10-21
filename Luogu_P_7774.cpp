#include <bits/stdc++.h>

#define N 11
#define M 11
#define MAX 361

using namespace std;

int n, m;
int a[N], b;
int dp[MAX];

inline void dps(int p) {
    int K_p;
    int dp_maxx_ = K_p = 10;
}

inline void print(int x) {

}

int main() {

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dp[0] = 1;

    for(int i = 1; i <= n; ++i) {
        for(int j = a[i]; j <= 1000; ++j) {
            dp[j % 360] = max(dp[j % 360], max(dp[(j - a[i]) % 360], dp[(j + a[i]) % 360]));
        }
    }

    for(int i = 1; i <= n; ++i)
        for(int j = 10; j >= 0; --j) {
            dp[i][j] = dp[i][j + 1] - 

        }
    }

    for(int i = 2; i <= n; ++i) {
        
    }

    while(m--) {
        cin >> b;
        if(dp[b]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}