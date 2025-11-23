#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 998244353;

// 树状数组 (Fenwick Tree)
struct BIT {
    vector<int> tree;
    int n;

    BIT(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
    
    // 查询 [l, r] 区间
    int query_range(int l, int r) {
        return query(r) - query(l - 1);
    }

    void clear() {
        tree.assign(n + 1, 0);
    }
};

// 快速幂
ll power(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 邻接表
vector<vector<int>> adj_T;
vector<vector<int>> children;
vector<int> tin, tout, flat_tree;
int timer;

// DFS 构建树结构、DFS序、扁平树
void dfs_build(int u, int p) {
    tin[u] = timer++;
    flat_tree.push_back(u);
    
    // 排序孩子，以模拟 sort(adj[x].begin(), adj[x].end())
    // 这一步是关键，我们必须基于给定的 T 建立父子关系
    // 然后找出哪些孩子是“按顺序”访问的
    // 不，我们不需要在这里排序。读入的 T 已经是 dfs 的结果
    // 我们只需要建立 T 的树形结构
    
    for (int v : adj_T[u]) {
        if (v != p) {
            children[u].push_back(v);
            dfs_build(v, u);
        }
    }
    tout[u] = timer; // tout[u] 是子树结束后的时间戳
}

struct Query {
    int id;
    int val; // 对应的 c 值
};

void solve() {
    int n;
    cin >> n;

    // 初始化/清空
    adj_T.assign(n, vector<int>());
    children.assign(n, vector<int>());
    tin.assign(n, 0);
    tout.assign(n, 0);
    flat_tree.clear();
    timer = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj_T[u].push_back(v);
        adj_T[v].push_back(u);
    }

    // 1. 构建以 0 为根的树，并获取 DFS 序
    dfs_build(0, -1);

    // 2. 创建查询
    vector<vector<Query>> queries_start(n);
    vector<vector<Query>> queries_end(n);
    vector<ll> answers;
    int query_id = 0;

    for (int u = 0; u < n; ++u) {
        // 关键：T 是 dfs 的结果，而 dfs 访问孩子是按编号排序的
        // 所以我们必须对 T 的孩子列表排序，才能正确模拟
        sort(children[u].begin(), children[u].end());

        for (int c : children[u]) {
            // 查询：c 的子树中（[tin[c], tout[c]-1]），有多少 v > c
            int l = tin[c];
            int r = tout[c] - 1; // tout 是开区间，所以 r 是 tout[c]-1
            int val = c;

            queries_start[l].push_back({query_id, val});
            queries_end[r].push_back({query_id, val});
            answers.push_back(0); // 为该 query_id 占位
            query_id++;
        }
    }

    // 3. 扫描线 + 树状数组
    BIT bit(n); // bit 维护 [0...n-1] 的值
    ll total_k = 0;

    for (int i = 0; i < n; ++i) { // i 是 DFS 序时间
        int v = flat_tree[i]; // v 是当前节点的值

        // 处理在 i 处开始的查询
        for (const auto& q : queries_start[i]) {
            // 查询 bit[q.val + 1 ... n-1]
            int count_gt = bit.query_range(q.val + 1, n - 1);
            answers[q.id] -= count_gt;
        }

        // 将当前节点加入 bit
        bit.add(v, 1);

        // 处理在 i 处结束的查询
        for (const auto& q : queries_end[i]) {
            // 查询 bit[q.val + 1 ... n-1]
            int count_gt = bit.query_range(q.val + 1, n - 1);
            answers[q.id] += count_gt;
        }
    }

    // 4. 汇总 k
    for (ll ans : answers) {
        total_k += ans;
    }

    // 5. 计算 2^k mod MOD
    cout << power(2, total_k) << "\n";
}

int main() {
    // 禁用 C++ 流同步，加快 IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, t;
    cin >> c >> t; // c 是样例编号，t 是数据组数
    while (t--) {
        solve();
    }
    return 0;
}