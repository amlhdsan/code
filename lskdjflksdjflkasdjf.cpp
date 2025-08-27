#include <iostream>
#include <vector>

// 使用 long long 防止中间计算溢出
using ll = long long;

ll N, M, P;

// 模块化快速幂: 计算 (base^exp) % P
ll power(ll base, ll exp) {
    ll res = 1;
    base %= P;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % P;
        base = (base * base) % P;
        exp /= 2;
    }
    return res;
}

// 模块化逆元: 计算 n^(-1) % P，使用费马小定理
ll modInverse(ll n) {
    return power(n, P - 2);
}

// 预计算阶乘和阶乘的逆元
std::vector<ll> fact;
std::vector<ll> invFact;

void precompute_factorials(int max_n) {
    fact.resize(max_n + 1);
    invFact.resize(max_n + 1);
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fact[i] = (fact[i - 1] * i) % P;
    }
    invFact[max_n] = modInverse(fact[max_n]);
    for (int i = max_n - 1; i >= 1; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % P;
    }
}

// 计算组合数 C(n, k) % P
ll combinations(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }
    // C(n, k) = n! / (k! * (n-k)!)
    return (((fact[n] * invFact[k]) % P) * invFact[n - k]) % P;
}

int main() {
    // 提高 IO 效率
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> N >> M >> P;
    
    // 处理 n=0 的特殊情况
    if (N == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // 组合数 C(n, k) 需要 n 最大达到 N*M + 2*N - 1
    ll max_comb_n = N * M + 2 * N;
    precompute_factorials(max_comb_n);

    ll count_tie = 0;
    for (ll i = 0; i <= 2 * N; ++i) {
        ll term1 = combinations(2 * N, i);
        ll upper_comb = N * M - i * (M + 1) + 2 * N - 1;
        ll lower_comb = 2 * N - 1;
        ll term2 = combinations(upper_comb, lower_comb);

        ll current_term = (term1 * term2) % P;

        if (i % 2 == 1) { // 奇数项是减
            count_tie = (count_tie - current_term + P) % P;
        } else { // 偶数项是加
            count_tie = (count_tie + current_term) % P;
        }
    }

    // 总结果数 = (M+1)^(2N)
    ll total_outcomes = power(M + 1, 2 * N);

    // 分子 = total_outcomes - count_tie
    ll numerator = (total_outcomes - count_tie + P) % P;

    // 分母 = 2 * total_outcomes
    ll denominator = (2 * total_outcomes) % P;
    
    // 最终结果 = 分子 * 分母的逆元
    ll result = (numerator * modInverse(denominator)) % P;

    std::cout << result << std::endl;

    return 0;
}