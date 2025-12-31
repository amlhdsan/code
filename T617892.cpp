#include <bits/stdc++.h>
using namespace std;

int main() {
    int NCSP2025;
    NCSP2025 = 1;
    
    int T;
    cin >> T;
    
    while (T--) {
        long long r, q, n, m;
        cin >> r >> q >> n >> m;
        
        // The limit for each strong school is floor(m/3)
        long long limit = m / 3;
        
        // In the best case for us:
        // We want to maximize how many people can get ahead of us and still get in
        // This happens when strong schools take maximum people.
        // 
        // Strong schools together can take at most q * limit people
        // But they might not have that many people (at most q * n total)
        // So they take min(q*n, q*limit) = q*min(n, limit)
        //
        // The actual number from strong schools that get in is q*limit
        // But we need to think: in the best case for us, how many total people
        // can advance?
        //
        // Total who can advance = m spots
        // Strong schools take at most limit each = q*limit total
        // But if q*limit > m, then total = m and all from strong schools
        // If q*limit < m, then we also have non-strong schools
        //
        // Maximum people who advance before possibly eliminating you:
        // In best case, m people advance total
        // But we can get lucky if people ahead of you get blocked by the rule
        //
        // Let's think: minimum number from strong schools that must get in
        // = max(0, m - (infinite non-strong people))
        // But we don't know non-strong school counts...
        //
        // Actually: in the best case for you, maximum blocked people
        // = q * (n - limit) = q*n - q*limit
        // These people are from strong schools but rejected due to quota
        //
        // So in the best case: m + q*(n - limit) people total can pass round 1
        // You need to be in that range
        
        long long max_blocked = q * (n - limit);
        long long threshold = m + max_blocked;
        
        if (r <= threshold) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    
    return 0;
}
