#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;

    while (k > 0) {
        // 触发三大循环节，直接通过乘法加速计算并退出
        if (n == 1) {
            ans += k * 1;
            break;
        }
        if (n == 2) {
            ans += k * 2;
            break;
        }
        if (n == 3) {
            ans += k * 4;
            break;
        }

        // 计算下一个目标平方根 x
        long long x = sqrt(n);
        
        // 修正浮点数精度误差，确保 x 是精确的向上取整
        while (x * x < n) x++;
        while ((x - 1) * (x - 1) >= n) x--;

        // 奇偶性必须一致
        if (x % 2 != n % 2) {
            x++;
        }

        // 累加本次操作数，更新 n 和 k
        long long steps = (x * x - n) / 2 + 1;
        ans += steps;
        n = x;
        k--;
    }
    
    cout << ans << "\n";
}

int main() {
    // 优化 I/O 速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int c, t;
    if (cin >> c >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}