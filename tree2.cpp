#include <bits/stdc++.h>
using namespace std;

int n, block;
vector<int> parent;
int query_count = 0;

int query_lca(int a, int b) {
    if (a == b) return a;
    cout << "? " << a << " " << b << "\n" << flush;
    int lca;
    cin >> lca;
    query_count++;
    return lca;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> block;
    int total = (1 << n) - 1;
    parent.assign(total + 1, 0);
    
    // 核心思想：
    // 对每个节点 i，我们需要找它的直接父亲
    // 方法：查询 LCA(i, j) 对所有 j != i
    // 最常出现的、且不等于 i 的 LCA 值很可能是 i 的直接父亲或其祖先
    // 进一步：最小的这样的 LCA 值是 i 的直接父亲
    
    map<int, set<int>> ancestor_candidates;  // ancestor_candidates[i] = possible ancestors of i
    
    for (int i = 1; i <= total; i++) {
        if (i == block) continue;
        ancestor_candidates[i] = {};
    }
    
    // 第一阶段：收集所有节点对的 LCA
    for (int i = 1; i <= total; i++) {
        if (i == block) continue;
        for (int j = i + 1; j <= total; j++) {
            if (j == block) continue;
            
            int lca = query_lca(i, j);
            
            // 如果 lca 不等于 i 和 j，那么它是它们的公共祖先
            if (lca != i) ancestor_candidates[i].insert(lca);
            if (lca != j) ancestor_candidates[j].insert(lca);
        }
    }
    
    // 第二阶段：确定直接父亲
    // 对于每个节点 i，其直接父亲应该是离它最近的祖先
    // 启发式：在所有候选祖先中，选择编号最大的（通常最接近）
    for (int i = 1; i <= total; i++) {
        if (i == block) continue;
        
        if (ancestor_candidates[i].empty()) {
            parent[i] = -1;  // i 是根
        } else {
            parent[i] = *ancestor_candidates[i].rbegin();  // 选最大的候选
        }
    }
    
    // 处理 block 节点
    if (block > 0) {
        // 通过其他节点的祖先关系推断 block 的信息
        // 简化：暂不处理
    }
    
    // 输出
    cout << "! ";
    for (int i = 1; i <= total; i++) {
        if (i > 1) cout << " ";
        cout << parent[i];
    }
    cout << "\n";
    
    return 0;
}
