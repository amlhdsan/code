#include <bits/stdc++.h>
using namespace std;

int find_lca(int a, int b) {
    set<int> ancestors_a;
    int u = a;
    while (u >= 1) {
        ancestors_a.insert(u);
        u /= 2;
    }
    u = b;
    while (u >= 1) {
        if (ancestors_a.count(u)) return u;
        u /= 2;
    }
    return 1;
}

int main() {
    // 模拟样例：n=2，但树结构为 2 是根，1 和 3 是孩子
    // 这与标准结构不同！
    // 标准 LCA：LCA(1,2)=1, LCA(1,3)=1, LCA(2,3)=1
    // 样例树 LCA：LCA(1,2)=2, LCA(1,3)=2, LCA(2,3)=2
    
    // 所以我不能用标准树测试！需要自定义树结构
    
    // 建立自定义树：2 是根，1 和 3 是孩子
    map<int, int> custom_parent;
    custom_parent[1] = 2;
    custom_parent[2] = -1;
    custom_parent[3] = 2;
    
    auto custom_lca = [&](int a, int b) -> int {
        set<int> ancestors_a;
        int u = a;
        while (u != -1) {
            ancestors_a.insert(u);
            u = (custom_parent.count(u) ? custom_parent[u] : -1);
            if (u == -1) break;
        }
        u = b;
        while (u != -1) {
            if (ancestors_a.count(u)) return u;
            u = (custom_parent.count(u) ? custom_parent[u] : -1);
            if (u == -1) break;
        }
        return -1;
    };
    
    int n = 2, block = 0;
    int total = (1 << n) - 1;
    
    cout << "Testing custom tree: 2 is root, 1,3 are children\n\n";
    
    map<int, set<int>> ancestor_candidates;
    for (int i = 1; i <= total; i++) {
        if (i == block) continue;
        ancestor_candidates[i] = {};
    }
    
    int query_count = 0;
    for (int i = 1; i <= total; i++) {
        if (i == block) continue;
        for (int j = i + 1; j <= total; j++) {
            if (j == block) continue;
            
            int lca = custom_lca(i, j);
            cout << "Query LCA(" << i << ", " << j << ") = " << lca << "\n";
            query_count++;
            
            if (lca != i) ancestor_candidates[i].insert(lca);
            if (lca != j) ancestor_candidates[j].insert(lca);
        }
    }
    
    cout << "\nAncestor candidates:\n";
    for (int i = 1; i <= total; i++) {
        cout << "Node " << i << ": {";
        for (int x : ancestor_candidates[i]) cout << x << " ";
        cout << "}\n";
    }
    
    vector<int> parent(total + 1);
    for (int i = 1; i <= total; i++) {
        if (ancestor_candidates[i].empty()) {
            parent[i] = -1;
        } else {
            parent[i] = *ancestor_candidates[i].rbegin();
        }
    }
    
    cout << "\nTotal queries: " << query_count << "\n";
    cout << "Result: ";
    for (int i = 1; i <= total; i++) {
        if (i > 1) cout << " ";
        cout << parent[i];
    }
    cout << "\n";
    
    cout << "\nExpected: 2 -1 2\n";
    
    return 0;
}
