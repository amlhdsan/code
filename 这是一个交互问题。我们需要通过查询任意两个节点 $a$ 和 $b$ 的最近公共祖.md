这是一个交互问题。我们需要通过查询任意两个节点 $a$ 和 $b$ 的最近公共祖先 (LCA) 来重建一棵 $n$ 层的满二叉树的父子关系。

核心思路是使用分治法。我们首先找到整棵树的根节点，然后将所有其他节点划分为左子树和右子树，接着递归地对左右子树进行相同的操作。





### 1. 寻找根节点 (Root)



树的根节点是所有 $N = 2^n - 1$ 个节点的（最终）公共祖先。

我们可以通过 $N-1$ 次查询找到它：

1. 任选一个节点（例如，标签为 $1$ 的节点）作为 "当前候选根" `current_root`。
2. 遍历所有其他节点 $i$（从 $2$ 到 $N$）。
3. 更新 `current_root = LCA(current_root, i)`。
4. 遍历完成后，`current_root` 的值就是整棵树的根 $R$ 的标签。

处理不可查询节点 block：

在上述过程中，我们不能将 block 作为查询的参数。

1. 创建一个列表 `non_blocked_nodes`，包含所有 $i \ne block$ 的节点。
2. 如果列表为空（只可能 $N=1$），根就是 `block`。
3. `current_root = non_blocked_nodes[0]`。
4. 遍历 `non_blocked_nodes[1:]` 中的所有节点 $i$。
5. `current_root = LCA(current_root, i)`。
6. 查询返回的 LCA *可以*是 `block`（我们只是不能*查询*它）。
7. 遍历完成后，`current_root` 就是真正的根 $R$。
8. 设置 `parent[R] = -1`。

这一步需要 $O(N)$ 次查询。



### 2. 分治 - 划分(Partition)与递归(Recurse)



我们设计一个递归函数 `Solve(nodes, root)`，它处理一个以 `root` 为根的子树，其所有节点（包括根）都在 `nodes` 集合中。

`Solve(nodes, root)` 的步骤：

1. **基本情况**: 如果 `nodes` 集合只包含 `root` (即 `len(nodes) == 1`)，说明它是一个叶子节点（在当前子树中），返回。
2. **找出后代**: `descendants = nodes - {root}`。
3. **处理 `block`**:
   - `non_blocked_desc = [x for x in descendants if x != block]`。
   - 如果 `non_blocked_desc` 为空（说明唯一的后代是 `block`），则 `parent[block] = root`，然后返回。
4. **选择枢轴(Pivot)**: `pivot = non_blocked_desc[0]`。
5. **划分左右子树**:
   - 初始化 `S_L = {pivot}` 和 `S_R = {}`。
   - 遍历 `non_blocked_desc[1:]` 中的所有节点 `y`。
   - 查询 `lca = LCA(pivot, y)`。
   - 如果 `lca == root`，说明 `pivot` 和 `y` 在 `root` 的不同子树中。将 `y` 加入 `S_R`。
   - 如果 `lca != root`，说明 `pivot` 和 `y` 在 `root` 的同一子树中。将 `y` 加入 `S_L`。
6. **安置 `block` 节点**:
   - 如果 `block` 节点在 `descendants` 中：
   - 我们知道满二叉树的左右子树大小相等，均为 `(len(nodes) - 1) / 2`。
   - `target_size = (len(nodes) - 1) / 2`。
   - 如果 `len(S_L) < target_size`，将 `block` 加入 `S_L`。
   - 否则，将 `block` 加入 `S_R`。
7. **寻找子树的根**:
   - `root_L = find_subtree_root(S_L)` (使用上面第1步中的 `block`-safe 方法)。
   - `root_R = find_subtree_root(S_R)` (使用上面第1步中的 `block`-safe 方法)。
8. **记录父节点**:
   - `parent[root_L] = root`
   - `parent[root_R] = root`
9. **递归**:
   - `Solve(S_L, root_L)`
   - `Solve(S_R, root_R)`



### 3. 复杂度分析



- **寻找全局根**: $O(N)$ 次查询。

- **`Solve(k)` (子树大小为 $k$)**:

  1. **划分**: $O(k)$ 次查询。
  2. **找 `root_L`**: $O(k/2)$ 次查询。
  3. **找 `root_R`**: $O(k/2)$ 次查询。
  4. **递归**: $2 \times \text{Solve}(k/2)$。

- 递归T(k)的复杂度为 $T(k) \approx 2k + 2T(k/2)$。

- 这导出了一个 $O(N \log N)$ 的总查询复杂度。

- 对于 $n=10$, $N \approx 1023$， $O(N \log N) \approx 1023 \times 10 \times C$。

- 精确计算 $n=10$ 的查询次数（如

  Total = (N-1) + S(n)，其中 $S(h) = 2^{h+1} - 7 + 2S(h-1)$），大约是 14,322 次。

- 这个数字远小于 $10^5$ 的限制，也小于 $4500$（为 Subtask 6 的满分）。

等等，重新检查 $n=10$ 的计算：

$S(2)=1, S(3)=11, S(4)=47, S(5)=151, S(6)=423, S(7)=1119, S(8)=2751, S(9)=6515, S(10)=14323$。

$Total = (1023-1) + 14323 = 1022 + 14323 = 15345$。

*这个数字（15,345）仍然小于 $10^5$，但大于 4,500。*

**优化**

存在一种更优的 $O(N)$ 随机化算法，或者一种 $O(N)$ 的确定性算法（通过更聪明地重用LCA查询结果），但 $O(N \log N)$ 的分治法在逻辑上是最清晰且肯定能通过 $10^5$ 限制的。对于 $4500$ 的限制，需要一个 $O(N)$ 的算法，例如：

1. **找根R**: $O(N)$
2. **找 $C_L, C_R$**: 划分 $N-1$ 个节点需要 $O(N)$ 查询。找到 $S_L, S_R$。
3. **对所有节点 $i$**: 找到 $i$ 的深度。这可以通过 $O(N)$ 查询实现（随机化）。`depth(i) = max(depth(LCA(i, j))) + 1` (对所有j)。
4. **对所有节点 $i$**: 找到 $parent(i)$。 $parent(i)$ 是 $i$ 的祖先中深度为 `depth(i) - 1` 的那个。

鉴于 $O(N \log N)$ 算法（~15k-20k 查询）已经能通过 $n=10$（$10^5$ 限制），我们将使用这个清晰的分治算法。



### 伪代码实现 (C++ 风格)



C++

```
#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <set>

using namespace std;

int n, block_node;
int N;
map<long long, int> memo; // 缓存LCA查询结果
int query_count = 0;

// 父亲数组
vector<int> parent;

// 交互函数
int ask(int a, int b) {
    if (a == block_node || b == block_node) {
        // 这是一个不应该发生的内部错误
        cerr << "Error: Querying blocked node " << block_node << endl;
        exit(1);
    }
    if (a > b) swap(a, b);
    
    // 使用 long long 来唯一标识 (a, b) 对
    long long key = (long long)a * (N + 1) + b;
    if (memo.count(key)) {
        return memo[key];
    }
    
    query_count++;
    if (query_count > 100000) {
        // 超过限制，但为了测试，我们可能继续
    }
    
    cout << "? " << a << " " << b << endl;
    int lca;
    cin >> lca;
    memo[key] = lca;
    return lca;
}

// 寻找一个节点集(node_set)的根
// 假设 node_set 不为空
int find_subtree_root(const set<int>& node_set) {
    vector<int> non_blocked;
    for (int node : node_set) {
        if (node != block_node) {
            non_blocked.push_back(node);
        }
    }

    if (non_blocked.empty()) {
        // 集合中唯一的节点就是 block_node
        return block_node;
    }

    int current_root = non_blocked[0];
    for (size_t i = 1; i < non_blocked.size(); ++i) {
        current_root = ask(current_root, non_blocked[i]);
    }
    return current_root;
}

// 递归分治函数
void solve(const set<int>& nodes, int root) {
    if (nodes.size() == 1) {
        return;
    }

    set<int> descendants;
    for (int node : nodes) {
        if (node != root) {
            descendants.insert(node);
        }
    }

    if (descendants.empty()) {
        return;
    }

    vector<int> non_blocked_desc;
    for (int node : descendants) {
        if (node != block_node) {
            non_blocked_desc.push_back(node);
        }
    }

    if (non_blocked_desc.empty()) {
        // 唯一的后代是 block_node
        parent[block_node] = root;
        return;
    }

    int pivot = non_blocked_desc[0];
    set<int> S_L, S_R;
    S_L.insert(pivot);

    for (size_t i = 1; i < non_blocked_desc.size(); ++i) {
        int y = non_blocked_desc[i];
        int lca = ask(pivot, y);
        if (lca == root) {
            S_R.insert(y);
        } else {
            S_L.insert(y);
        }
    }

    // 安置 block_node (如果它在后代中)
    if (descendants.count(block_node)) {
        int target_size = (nodes.size() - 1) / 2;
        if (S_L.size() < target_size) {
            S_L.insert(block_node);
        } else {
            S_R.insert(block_node);
        }
    }

    // 找到左右子树的根
    int root_L = find_subtree_root(S_L);
    int root_R = find_subtree_root(S_R);

    parent[root_L] = root;
    parent[root_R] = root;

    // 递归
    solve(S_L, root_L);
    solve(S_R, root_R);
}


int main() {
    cin >> n >> block_node;
    N = (1 << n) - 1;
    parent.resize(N + 1);

    set<int> all_nodes;
    for (int i = 1; i <= N; ++i) {
        all_nodes.insert(i);
    }

    // 1. 找到全局根
    int global_root = find_subtree_root(all_nodes);
    parent[global_root] = -1;

    // 2. 开始分治
    solve(all_nodes, global_root);

    // 3. 输出答案
    cout << "!";
    for (int i = 1; i <= N; ++i) {
        cout << " " << parent[i];
    }
    cout << endl;

    return 0;
}
```