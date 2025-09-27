#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using i128  = __int128_t;

/* convert __int128 to decimal string */
string toString(i128 x) {
    if (x == 0) return "0";
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }
    string s;
    while (x > 0) {
        int digit = int(x % 10);
        s.push_back('0' + digit);
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

/* comparator for decreasing a/b  (cross‑multiply, avoid floating point) */
bool cmpRatio(const pair<int64,int64>& p1,
              const pair<int64,int64>& p2)
{
    // want p1 before p2  ⇔  p1.a / p1.b > p2.a / p2.b
    // i.e.  p1.a * p2.b > p2.a * p1.b
    __int128 left  = (__int128)p1.first  * p2.second;
    __int128 right = (__int128)p2.first  * p1.second;
    return left > right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    int n;
    long long A_dummy, B_dummy;          // A,B are only given for the whole test file, not needed
    if(!(cin >> T >> n >> A_dummy >> B_dummy)) return 0;
    // the same n, A, B are used for every of the T cases
    
    for (int tc = 0; tc < T; ++tc) {
        vector<pair<int64,int64>> v(n);
        for (int i = 0; i < n; ++i) {
            int64 a,b;
            cin >> a >> b;
            v[i] = {a,b};
        }
        sort(v.begin(), v.end(), cmpRatio);
        
        vector<int64> prefA(n+1,0), prefB(n+1,0);
        for (int i = 1; i <= n; ++i) {
            prefA[i] = prefA[i-1] + v[i-1].first;
            prefB[i] = prefB[i-1] + v[i-1].second;
        }
        int64 totalB = prefB[n];
        i128 best = 0;
        for (int k = 0; k <= n; ++k) {
            i128 A = prefA[k];
            i128 B = totalB - prefB[k];
            i128 cur = A * B;
            if (cur > best) best = cur;
        }
        cout << toString(best) << '\n';
    }
    return 0;
}
