#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, y, p;
long long ans = 0;

int c(int n, int m) {
    int a = 1, b = 1, c = 1;
    for (int i = n; i >= 1; --i) 
        a *= i;
    for (int i = m; i >= 1; --i) 
        b *= i;
    for (int i = n - m; i >= 1; --i) 
        c *= i;
    return a / (b * c);
}

int main() {
    cin >> n >> y >> p;

    for(int x = 0; x <= n && x + y <= n && x + y >= 0; ++x) {
        ans += c(n, x) * c(n, x + y);
    }

    cout << ans % p << endl;
    
    return 0;
}