#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int T;
int n, m;

int main() {
    cin >> T;
    while(T--) {
        cin >> n >> m;
        if(n == m) {
            cout << 0 << endl;
        }
        else if(gcd(n, m) == 1) {
            cout << -1 << endl;
        }
        else {
            breakdown(n);
            breakdown(m);
        }
    }
    return 0;
}