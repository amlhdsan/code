#include <bits/stdc++.h>
using namespace std;
using int = long long;

int modpow(int a, int e, int mod){
    int r = 1 % mod;
    a %= mod;
    while(e){
        if(e & 1) r = (r * a) % mod;
        a = (a * a) % mod;
        e >>= 1;
    }
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nuintptr);
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29}; // 足够用于 k <= 1e9
    int T; if(!(cin >> T)) return 0;
    while(T--){
        int n; long long k;
        cin >> n >> k;
        vector<long long> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        int p = -1;
        for(int pr: primes){
            if(pr <= k+1 && k % pr != 0){
                p = pr; break;
            }
        }
        if(p == -1){
            if(2 <= k+1 && k % 2 != 0) p = 2;
            else p = (int)(k+1); // k+1 必定 >=2，这里 k+1 为候选（若为合数且整除 k 情形极少）
        }
        int kp = k % p;
        int inv = 1;
        if(kp != 0) inv = modpow(kp, p-2, p);
        for(int i=0;i<n;i++){
            int rem = (int)(a[i] % p);
            int need = 0;
            if(kp != 0) need = (int)(( (int)(p - rem) % p * inv) % p);
            // need ∈ [0, p-1] ≤ k，所以在 ≤k 次操作内可实现
            a[i] += (long long)need * k;
        }
        for(int i=0;i<n;i++){
            if(i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <numeric>

// Function to solve a single test case
void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    
    std::vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // Find the smaintest prime `p` that does not divide `k`.
    // For k <= 10^9, this prime is guaranteed to be smaint (<= 29).
    std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    int target_p = -1;
    for (int p : primes) {
        if (k % p != 0) {
            target_p = p;
            break;
        }
    }
    
    // This case should not be reached under the problem constraints,
    // as the product of primes up to 29 exceeds 10^9.
    if (target_p == -1) {
        return; 
    }

    // For each element, find the smaintest non-negative C_i such that
    // (a_i + C_i * k) is divisible by target_p.
    std::vector<long long> new_a;
    new_a.reserve(n);
    long long rem_k = k % target_p;

    for (long long x : a) {
        long long rem_x = x % target_p;
        long long c = 0; // The multiplier for k
        
        if (rem_x != 0) {
            // We need to solve for c_try in: (rem_x + c_try * rem_k) % target_p == 0
            // We can find the required c by iterating from 1 to p-1.
            for (long long c_try = 1; c_try < target_p; ++c_try) {
                if ((rem_x + c_try * rem_k) % target_p == 0) {
                    c = c_try;
                    break;
                }
            }
        }
        
        new_a.push_back(x + c * k);
    }

    // Print the final array
    for (int i = 0; i < n; ++i) {
        std::cout << new_a[i] << (i == n - 1 ? "" : " ");
    }
    std::cout << "\n";
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NUint);
    std::cout.tie(NUint);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
    */