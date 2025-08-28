#include <iostream>
#include <vector>
#include <string>
#include <numeric>

// 使用预编译指令或函数来加速C++的I/O
void fast_io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
}

// 解决单个测试用例的函数
void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    // 使用滑动窗口检查是否存在连续 k 个 '1'
    int ones_count = 0;
    bool found_block = false;

    // 初始化第一个窗口
    for (int i = 0; i < k; ++i) {
        if (s[i] == '1') {
            ones_count++;
        }
    }

    if (ones_count == k) {
        found_block = true;
    } else {
        // 滑动窗口
        for (int i = k; i < n; ++i) {
            // 将新元素加入窗口
            if (s[i] == '1') {
                ones_count++;
            }
            // 将旧元素移出窗口
            if (s[i - k] == '1') {
                ones_count--;
            }
            // 检查当前窗口是否满足条件
            if (ones_count == k) {
                found_block = true;
                break;
            }
        }
    }

    if (found_block) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
        
        // 创建结果数组 p 和用于存储下标的向量
        std::vector<int> p(n);
        std::vector<int> zeros_indices;
        std::vector<int> ones_indices;

        // 分类存储 '0' 和 '1' 的下标
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                zeros_indices.push_back(i);
            } else {
                ones_indices.push_back(i);
            }
        }

        // 将小数字 1, 2, ... 分配给 s_i=1 的位置
        int val = 1;
        for (int idx : ones_indices) {
            p[idx] = val++;
        }

        // 将大数字 n, n-1, ... 分配给 s_i=0 的位置
        val = n;
        for (int idx : zeros_indices) {
            p[idx] = val--;
        }

        // 输出最终的排列
        for (int i = 0; i < n; ++i) {
            std::cout << p[i] << (i == n - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    // 加速I/O
    fast_io();

    // 读取测试用例数量
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}