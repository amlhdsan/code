#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    if (!(cin >> a >> b)) return 0;
    long long ans = max(a, b);
    cout << fixed << setprecision(8) << double(ans) << "\n";
    return 0;
}
