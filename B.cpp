#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline void 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long total_moves = 0;
        long long alice = 0, bob = 0;
        for (int i = 0; i < n; i++) {
            long long f;
            if (i == 0) {
                f = a[i];
            } else {
                f = a[i] - a[i-1];
            }
            long long s = n - i;
            if (total_moves % 2 == 0) {
                alice += (f + 1) / 2 * s;
                bob += f / 2 * s;
            } else {
                alice += f / 2 * s;
                bob += (f + 1) / 2 * s;
            }
            total_moves += f;
        }
        cout << alice << " " << bob << "\n";
    }
    return 0;
}
