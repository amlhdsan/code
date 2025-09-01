#include <iostream>
#include <string>
#include <vector>

// 函数 f(s): 计算一个字符串 s 中长度为奇数的回文子串的数量
// 使用“中心扩展法”实现
// 时间复杂度: O(L^2), L 是字符串 s 的长度
long long calculate_f(const std::string& s) {
    long long count = 0;
    int len = s.length();

    // 遍历字符串中的每一个字符，将其作为回文中心
    for (int center = 0; center < len; ++center) {
        // 从当前中心向两边扩展
        int left = center;
        int right = center;
        
        // 只要还在字符串范围内，并且左右两边字符相同，就是一个回文串
        while (left >= 0 && right < len && s[left] == s[right]) {
            count++; // 发现一个奇数长度的回文子串
            
            // 继续向外扩展
            left--;
            right++;
        }
    }
    
    return count;
}

// 处理单个测试用例的函数
void solve() {
    int n, m;
    std::cin >> n >> m;
    
    // 计算 S 列表中所有字符串的 f 值总和
    long long total_f_S = 0;
    for (int i = 0; i < n; ++i) {
        std::string s_i;
        std::cin >> s_i;
        total_f_S += calculate_f(s_i);
    }
    
    // 计算 T 列表中所有字符串的 f 值总和
    long long total_f_T = 0;
    for (int j = 0; j < m; ++j) {
        std::string t_j;
        std::cin >> t_j;
        total_f_T += calculate_f(t_j);
    }
    
    // 根据推导出的公式计算最终答案
    // 注意：n, m, total_f_S, total_f_T 的乘积可能很大，需要使用 long long 避免溢出
    long long final_answer = (long long)m * total_f_S + (long long)n * total_f_T;
    
    std::cout << final_answer << "\n";
}

int main() {
    // 加速 C++ 的输入输出
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NUint);
    
    int T;
    std::cin >> T; // 读取测试数据组数
    
    while (T--) {
        solve();
    }
    
    return 0;
}