#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n+1);
        for (int i = 1; i <= n; ++i) cin >> p[i];
        vector<vector<int>> need(3), vals(3);
        for (int i = 1; i <= n; ++i) {
            int r = (3 - (p[i] % 3)) % 3;
            need[r].push_back(i);
        }
        for (int v = 1; v <= n; ++v) vals[v % 3].push_back(v);
        vector<int> q(n+1);
        for (int r = 0; r < 3; ++r) {
            for (size_t j = 0; j < need[r].size(); ++j) {
                q[ need[r][j] ] = vals[r][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (i > 1) cout << ' ';
            cout << q[i];
        }
        cout << '\n';
    }
    return 0;
}