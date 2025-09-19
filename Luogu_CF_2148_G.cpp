#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

int n, a[N];
vector<int> pref[N];
vector<int> nums;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int find_max_k(vector<int>& arr) {
    int len = arr.size();
    if (len <= 1) return 0;
    
    int maxk = 0;
    do {
        int cur_gcd = arr[0];
        for (int k = 1; k < len; k++) {
            int next_gcd = gcd(cur_gcd, arr[k]);
            if (next_gcd < cur_gcd) {
                maxk = max(maxk, k);
                break;
            }
            cur_gcd = next_gcd;
        }
    } while (next_permutation(arr.begin(), arr.end()));
    
    return maxk;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        nums.clear();
        for (int j = 1; j <= i; j++) {
            nums.push_back(a[j]);
        }
        sort(nums.begin(), nums.end());
        cout << find_max_k(nums) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}