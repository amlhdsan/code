#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void solve() {
    int n, k, p;
    long long m;
    if (!(cin >> n >> k >> p >> m)) return;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 赢牌（Win-condition）的固定成本，注意下标从 0 开始
    long long win_val = a[p - 1];

    // --- 第一步：计算第一次播放赢牌的最小总成本 ---
    long long cost_first = win_val;
    if (p > k) {
        // 必须从前 p-1 张牌中选出 p-k 张最便宜的移到队尾
        vector<long long> prefix;
        for (int i = 0; i < p - 1; ++i) {
            prefix.push_back(a[i]);
        }
        sort(prefix.begin(), prefix.end());
        for (int i = 0; i < p - k; ++i) {
            cost_first += prefix[i];
        }
    }

    // 如果连第一次都买不起，直接出局
    if (m < cost_first) {
        cout << 0 << endl;
        return;
    }

    // --- 第二步：计算后续每循环一次的最小成本 ---
    long long cost_cycle = win_val;
    if (n > k) {
        // 赢牌播完后在位置 n，需要移动 n-k 张杂牌才能让它回到前 k 位
        // 此时我们可以从除赢牌外的所有 (n-1) 张牌中选最便宜的
        vector<long long> others;
        for (int i = 0; i < n; ++i) {
            if (i == p - 1) continue;
            others.push_back(a[i]);
        }
        sort(others.begin(), others.end());
        for (int i = 0; i < n - k; ++i) {
            cost_cycle += others[i];
        }
    }

    // --- 第三步：计算最大次数 ---
    // 第一次之后剩余的能量：m - cost_first
    long long remaining_m = m - cost_first;
    long long additional_times = remaining_m / cost_cycle;

    cout << 1 + additional_times << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}