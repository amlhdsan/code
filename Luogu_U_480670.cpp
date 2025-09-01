#include <bits/stdc++.h>

#define int long long

using namespace std;

int T, n, k;
int ans;
int l, r;

int main() {

    cin >> T;
    while(T--) {
        ans = 0;
        cin >> n >> k;
        l = n / (k + 1) + 1;
        r = n / k;
        if(k == 0) {
            cout << 1 << endl;
            continue;
        }
        if(r < l) {
            cout << 0 << endl;
            continue;
        }
        cout << (r - l + 1) << endl;
    }

    return 0;
}