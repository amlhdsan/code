#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 5;
int n, c;
int p[N];
vector<int> pos[N];

ll solve() {
    for(int i = 1; i <= n; i++) pos[p[i]].push_back(i);
    
    ll ans = 0;
    for(int i = 0; i < c; i++) {
        if(pos[i].empty()) continue;
        for(int j = i + 1; j < c; j++) {
            if(pos[j].empty()) continue;
            for(int k = j + 1; k < c; k++) {
                if(pos[k].empty()) continue;
                if((j - i + c) % c <= c/2 && 
                   (k - j + c) % c <= c/2 && 
                   (i - k + c) % c <= c/2) continue;
                ans += 1LL * pos[i].size() * pos[j].size() * pos[k].size();
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> p[i];
    cout << solve() << "\n";
    return 0;
}