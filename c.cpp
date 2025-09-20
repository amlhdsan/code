#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        bool ok = true;
        for (int i = 1; i + 1 < n; ++i) {          // interior positions
            if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1') {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
